#include <iostream>
#include <ctime>

using namespace std;


int main (){

     int box[5] = {1, 2, 3, 4, 5};     // Numbers for display
     int guesse ,trais = 3  ;
    

    srand(time(0));

    const char insade[5] = {'E', 'E', 'E', 'E', 'E'};
    const char kbom = '*';
    char result[5];                    // Status: 'E' or '*'

     
                                int bomb_pos = rand() % 5;
                                result[bomb_pos] = kbom ;  



    cout  << " ___     ___     ___     ___     ___  \n";
    cout  << "| "<<box[0]<<" |\t"<< "| "<<box[1]<<" |\t"<< "| "
          <<box[2]<<" |\t"<< "| "<<box[3]<<" |\t"<< "| "<<box[4]<<" |\t\n";
    cout  << " ___     ___     ___     ___     ___  \n";
    


    do
    {
        
                        
    cout << "enter the numeber of the box tht have the boom...";
    cin >> guesse ;
                       cout << "_____________is is your "<<trais<< " _____________"<<endl;

    // Initialize result array
                                for(int i = 0; i < 5; i++) {
                                    result[i] = insade[i];  
                                }

   // Place bomb

   // Display box result
                                for(int i = 0; i < 5; i++) {


                                   
                                
                                if  (i==guesse)  {   
                                            cout  << " ___     \n";
                                    cout  << "| " << result[i] << "  |\n";
                                            cout  << " ___    \n";

                                            if(trais >2 && result[i]=='E'){
                                                cout << "BOOOOOOOM!!!!" <<endl;
                                                         
                                            break;
                                            }
                                           else if(trais >3 && result[i]=='*'){
                                                cout << "You found the bomb!" <<endl;
                                            }
                                            else     cout << "keep saerching..." <<endl;


                                }
                                
                                   else if (i<5)  {                 
                                            cout  << " ___     \n";
                                    cout  << "| " << box[i] << "  |\n";
                                            cout  << " ___    \n";

                                        // if(i==result[5])      cout << "keep saerching..." <<endl;


                                }
                                 
                               

                            }
                  trais--;
           } while (trais!=0);

                        cout << "__________________________"<< endl;
         

return 0;
}
