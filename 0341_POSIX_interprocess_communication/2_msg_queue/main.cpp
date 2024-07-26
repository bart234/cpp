#include "sources.h"
constexpr auto MAX_SIZE = 50;

namespace chapter_7_concurenncy_simple_and_linux_IPC
{  

    namespace egzample_of_posix_msg_queue
    {        
        std::string QUEUE_NAME = "/test_queue";
        

        void readFromQueue()
        {
            cout<<"Writter starting"<<endl;

            mqd_t   mq = {0};           //type for mssg queue
            struct mq_attr attr = {0};  //struct for keeping mq parameters   
            attr.mq_flags =0;
            attr.mq_maxmsg =10;
            attr.mq_msgsize = MAX_SIZE;
            attr.mq_curmsgs = 0;

            array<char, MAX_SIZE> buffer__char_arr{};

            mq=mq_open(QUEUE_NAME.data(), O_CREAT | O_RDONLY, 0700, &attr);
            //mq_open - on opern correct return file descriptior
            //mq_open - on open failed return -1 and fullfill errno

            if(mq>-1){
                    for(;;){
                            //we read in loop chunk of data  specify by buffer arr created previously                        
                            //bytes_read it is t_size - number of readed chars
                            auto bytes_read = mq_receive(mq, buffer__char_arr.data(), buffer__char_arr.size(),NULL);
                                
                            if(bytes_read> 0){            //reading + printing - we not saving it
                                buffer__char_arr[bytes_read] ='\0'; //add  c-string ending at the end
                                cout<<" Recived: "<<buffer__char_arr.data()<< endl;
                            
                            }else if (bytes_read == -1){    //error
                                perror("readFromQueue:  recived msg failed");

                            }else{                          // end
                                cout<<"\n\n End of reading data"<<endl;
                                mq_close(mq);
                                break;
                            }
                    }//end for

            }else{

                cout<<"Reader: failed to laod queue"<<strerror(errno)<<endl;
            }

            // remove link to queue
            mq_unlink(QUEUE_NAME.data());


        }

        void writeInToQueue()
        {
            cout<<"Writting started"<<endl;

            //1th - check if queue is open - if no-> error
            //mq_open - on opern correct return file descriptior
            //mq_open - on open failed return -1
            mqd_t mq={0};

            mq=mq_open(QUEUE_NAME.data(), O_WRONLY, 0700, NULL);
            if(mq>-1){

                    //2nd - open and check file descriptior for open(work) on a mq object - here saved as test.dat 
                    int file_descriptior = open("mq_test.dat", O_RDONLY);
                    if(file_descriptior>0){

                            //3th - in that step  mq(exist), fd(is open) we can read data
                            //we create inner array and another buffer to read chars from message 
                            array<char, MAX_SIZE> inner_buffer{};
                            for(;;)
                            {                         
                                //4th - if we ahve something to process - read it, if not- close it      
                                auto bytes_to_send_to_queue = read(file_descriptior, inner_buffer.data(), inner_buffer.size());
                                
                                if(bytes_to_send_to_queue> 0){
                                        //we just wrtie - nothing else
                                                //check if we have 
                                                auto end_sending_check = mq_send(mq,inner_buffer.data(),inner_buffer.size(),0);
                                                if (end_sending_check == -1) { //-1 == error
                                                    cout<<"Sending ends on case  read >0: Send error"<<strerror(errno)<<endl;
                                                }
                                        //break;

                                }else if (bytes_to_send_to_queue == 0) { // here sending is end
                                        cout<<"Sending ends..."<<endl;
                                        
                                                //another check if we got all and there is no error
                                                auto end_sending_check = mq_send(mq,inner_buffer.data(),0,0);
                                                if (end_sending_check == -1) { //-1 == error
                                                    cout<<"Sending ends on case read ==0: Send error"<<strerror(errno)<<endl;
                                                }
                                        break;


                                }else{  //here we catch error
                                    perror("Loading loop: Reading failed");
                                }



                            }   //end for          


                    
                    }else{
                        cout<<"fd: Reading from file - failed"<<endl;;
                    }

                    //close fd and msg queue
                    close(file_descriptior);
                    mq_close(mq);


            }else{
                cout<<"readFromQueue: Failed to open msg queue"<<strerror(errno)<<endl; //strerror from cstring lib
            }



        }

        void run_me()
        {
            cout<<"-------------ch7_start----------------"<<endl;
            //eg_1_data_race_on_variable();
            thread th_read {egzample_of_posix_msg_queue::readFromQueue};
            thread th_write {egzample_of_posix_msg_queue::writeInToQueue};
            th_read.join();
            th_write.join();

            

            cout<<"-------------ch7_end----------------"<<endl;
        }

    }
}