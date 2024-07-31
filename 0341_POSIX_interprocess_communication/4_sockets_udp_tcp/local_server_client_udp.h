#ifndef SOURCES_H
#define SOURCES_H
#include "sources.h"
#endif


int dice_roll()
{
    auto min{1};
    auto max{6};
    auto roll{rand()%(max-min+1)+min};
    return roll;
}

void process_creator()
{
    auto socket_file_descriptor=0;
    array<char,BUF_SIZE> buffer_arr_for_data{};
    string_view stop_requests{"no more requests"};
    string_view start_request{" Throw dice!"};

    struct sockaddr_in server_address{};
        //socket config
        server_address.sin_family =         AF_INET;    
        server_address.sin_addr.s_addr=     INADDR_ANY; 
        server_address.sin_port=            htons(PORT);

    struct sockaddr_in client_address{};


    //create two processes 
    //if with initlializer if(initlialization; check->bool)
    if(int pid=fork(); pid==0){
        
        //AF_INET (mean it rely on Ipv4), we use UDP through SOCK_DGRAM setting socket
        if(socket_file_descriptor=socket(AF_INET,SOCK_DGRAM,0);
           socket_file_descriptor<0)
        {
            const auto ecode{make_error_code(errc{errno})};
            cerr<< "Error during socket opening";
            system_error exception{ecode};
            throw exception;
        }

        //it binds fd with socket config with server address
        if(bind(socket_file_descriptor, 
                (const struct sockaddr*)&server_address, 
                sizeof(server_address))
            <0)
        {
            const auto ecode{make_error_code(errc{errno})};
            cerr<<" Error during binding";
            system_error exception{ecode};
            throw exception;
        }

        socklen_t len_of_client_addres = sizeof(client_address);


        //process itself---------------------------------------------------------------------------------------
        
        for(;;)
        {       
            //when request for new dice roll is recived  - bytes recived > 0
            if(auto bytes_recived = recvfrom(   socket_file_descriptor,
                                                buffer_arr_for_data.data(),
                                                buffer_arr_for_data.size(),
                                                MSG_WAITALL,
                                                (struct sockaddr*)&client_address,
                                                &len_of_client_addres);
                    bytes_recived >=0)
            {

                buffer_arr_for_data.data()[bytes_recived]='\0';
                cout<<" Request recived: " <<buffer_arr_for_data.data()<<endl;
                

                    //compare - requestor sending 2 kind od messages 
                    //1th - start_resuest - to get data  from dice roll
                    //2nd - stop request - at the end, to finish communication 
                    //we roll dice and sendto
                    //MSG_WAITALL  -mean it will block calling process - usually when there is no incoming data
                    //in udp communication: no packet order, reciving 0 bytes (by recvfrom) is valid
                    if(start_request.compare(0,bytes_recived,buffer_arr_for_data.data())==0){
                        string_view res_data{std::to_string(dice_roll())};
                        cout<<"Producer: rolling dice - done"<<endl;
                        sendto(socket_file_descriptor,
                                res_data.data(),
                                res_data.size(),
                                MSG_WAITALL,
                                (struct sockaddr*)&client_address,
                                len_of_client_addres);
                        cout<<"Producer: sending result - done"<<endl;
                    }
                    else 
                    {
                        cout<<"Producer: communication end"<<endl;
                        break;
                    }

            //we dont recive request
            }else{
                const auto ecode{make_error_code(errc{errno})};
                cerr<<"Recive failed";
                system_error exception{ecode};
                throw exception;
            }
        }

        //closing communication
        if(auto res =close(socket_file_descriptor);res == -1){
            const auto ecode{make_error_code(errc{errno})};
            cerr<<"Error during socket closing";
            system_error exception{ecode};
            throw exception;
        }else{
            cout<<"Producer: closing communication fd"<<endl;
        }

        exit(EXIT_SUCCESS);


    }else if (pid >0){ //for if pid !=0  it is sever 
        int32_t number_of_dice_rolls;
        cout<<"Chose how many time would you like ot roll dice (1 to 256)"<<endl;
        cin>>number_of_dice_rolls;
        //check boundries,isnumeric - skipped

        //
        if
        (
            (socket_file_descriptor = socket(AF_INET,SOCK_DGRAM,0))<0   
            //carefull on things like that, without 1th bracket you will get wierd behavior
            //and fd will not load
        )
        {
           const auto ecode{make_error_code(errc{errno})};
            cerr<<"Error during socket opening";
            system_error exception{ecode};
            throw exception;
        }

        socklen_t len   =0;

        for(auto i = 1;i <= number_of_dice_rolls; i++){
            //in loop it sending request for dice rolls
            // content of that msg is - give me dice roll 
            //MSG_DONT_WAIT - we just sending request here, we dont expect return msg here
            //mean- rerutn msg - about if they recive data, not reponse 
            if(auto b_sent = sendto(socket_file_descriptor,
                                    start_request.data(),
                                    start_request.size(),
                                    MSG_DONTWAIT,
                                    (const struct sockaddr*)&server_address,
                                    sizeof(server_address)); 
                    b_sent >=0)
            {}
            
            else{
                const auto ecode{make_error_code(errc{errno})};
                cerr<<"Send request failed";
                system_error exception{ecode};
                throw exception;
            }

            //this is message from recive - response for our request
            //MSG_WAIT - is block calling process - we jsut waiting for response msg
            if(auto b_recv =recvfrom(socket_file_descriptor,
                                        buffer_arr_for_data.data(),
                                        buffer_arr_for_data.size(),
                                        MSG_WAITALL,
                                        (struct sockaddr*)&server_address,
                                        &len);
                    b_recv > 0)
            {
                buffer_arr_for_data.data()[b_recv] = '\0';
                cout<<"Dice  roll request, for throw number: "<< i<<" is "<<buffer_arr_for_data.data()<<endl;
            }
        } //end for loop
        

        //request with message to stop communication - it expect to response from reciver
        //and its telling Data LInk layer of the OSI model that there is a succesful reply
        sendto(socket_file_descriptor,
                stop_requests.data(),
                stop_requests.size(),
                MSG_CONFIRM,
                (struct sockaddr*)&server_address,
                sizeof(server_address));


        if(auto res = close(socket_file_descriptor); res == -1){
            const auto ecode{make_error_code(errc{errno})};
            cerr<<"Error closing socket";
            system_error exception{ecode};
            throw exception;
        }

        //exit{EXIT_SUCCESS};

    } //end for if pid==0
    else
    {
        const auto ecode{make_error_code(errc{errno})};
        cerr<<"Process creation failed";
        system_error exception{ecode};
        throw exception;

    }
    
}
