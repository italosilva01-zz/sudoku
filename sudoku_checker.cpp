#include <iostream>
#include <algorithm>
#include <sstream>

#define EMPTY short(0)
#define SIZE 9
typedef short n_boards[SIZE][SIZE];

void print( short b[SIZE][SIZE] )
{
    int contColum,contLine;/*as variáveis contColum e contline 
                            contam a quantidade de elementos que
                            printados.*/
    contColum = 0;
    contLine = 0;

    
   for(int line = 0; line< SIZE; line++){
       //for para linhas
       ++contLine;
       for(int column = 0;column<SIZE;column++){
           //for para colunas 

           std::cout<< b[line][column]<<" ";
            contColum++; 
                
            if(contColum == 3){
                //só executa quando três elementos foram printados
                std::cout <<" ";
                contColum = 0;
            }
       }
       //quebrar a linha, delimitando a matriz
       std::cout<<std::endl;
    if(contLine==3){
        //quebra uma linha quando tiver printado uma tabela inteira.
        std::cout<<std::endl;
        contLine = 0;
    }
       
   }
}

bool check_row(int row,short v[SIZE][SIZE])
{
    //This function check the row of vector
    
    int aux[10]{0,0,0,0,0,0,0,0,0,0};
    //vector auxiliary

    for(int column = 0;column < SIZE; column++ ){
    //This 'for' moving on in the array line
        if(v[row][column]== 0){
            //checks the value in the vector and marks the auxiliary vector
            aux[0] += 1;
        }else if(v[row][column]==1){
            aux[1] += 1;
        }else if(v[row][column]==2){
            aux[2] += 1;
        }else if(v[row][column]==3){
            aux[3] += 1;
        }else if(v[row][column]==4){
            aux[4] += 1;
        }else if(v[row][column]==5){
            aux[5] += 1;
        }else if(v[row][column]==6){
            aux[6] += 1;
        }else if(v[row][column]==7){
            aux[7] += 1;
        }else if(v[row][column]==8){
            aux[8] += 1;
        }
        else if(v[row][column]==9){
            aux[9] += 1;
        }

        


    };
    
    for(int pos = 0; pos < SIZE; pos++){
        //check if any element is greater than 1
        if(aux[pos]>1){
            return false;
        }
    }
    return true;
}
bool check_column(int column, short v[SIZE][SIZE]){
    int aux[10]{0,0,0,0,0,0,0,0,0,0};

    for( int row = 0; row<SIZE; ++row){
        
        if(v[row][column]== 0){
            aux[0]+=1;
        }else if(v[row][column] == 1){
            aux[1]+=1;
        }else if(v[row][column] == 2){
            aux[2]+=1;
        }else if(v[row][column] == 3){
            aux[3]+=1;
        }else if(v[row][column] == 4){
            aux[4]+=1;
        }else if(v[row][column] == 5){
            aux[5]+=1;
        }else if(v[row][column] == 6){
            aux[6]+=1;
        }else if(v[row][column] == 7){
            aux[7]+=1;
        }else if(v[row][column] == 8){
            aux[8]+=1;
        }else if(v[row][column] == 9){
            aux[9]+=1;
        }


    }

    for(int pos = 0; pos < SIZE; ++pos){
        if(aux[pos] >1){
            return false;
        }
    }
    return true;
}

bool check_quadrant(short v[SIZE][SIZE]){
    int aux[10]{0,0,0,0,0,0,0,0,0,0};

    for(int rowQuadrant = 0; rowQuadrant< SIZE; rowQuadrant+=3){
        for(int columnQuadrant = 0; columnQuadrant < SIZE; columnQuadrant +=3){

            for(int row = rowQuadrant; row<rowQuadrant+3; ++row){
                for(int column = columnQuadrant; column < columnQuadrant+3; ++column){
                    
                    switch (v[row][column])
                    {
                    case 0: aux[0]+=1; break;
                    case 1: aux[1]+=1;break;
                    case 2: aux[2]+=1;break;
                    case 3: aux[3]+=1;break;
                    case 4: aux[4]+=1;break;
                    case 5: aux[5]+=1;break;
                    case 6: aux[6]+=1;break;
                    case 7: aux[7]+=1;break;
                    case 8: aux[8]+=1;break;
                    case 9: aux[9]+=1;break;
                    }

                }
            }

            for(int pos = 0;pos<10;++pos){
              
                if(aux[pos]>1){
                    return false;
                }
                
            };
            for(int pos = 0; pos < 10;++pos){
                aux[pos]=0;
            }
            
        }
    }
    return true;
}
bool is_valid( short b[SIZE][SIZE] )
{
    // TODO: implement this function.
    //check line
    for(int row = 0; row<SIZE; ++row){
        if(check_row(row,b)==false){
            return false;
        }
    }
    //check column
    for(int column = 0; column<SIZE; ++column){
        if(check_column(column,b)==false){
            return false;
        }
    }
   if(check_quadrant(b)!= true){
       return false;
   } 
    return true; // This is just a stub. Replace it as needed.
}

void add_dates(n_boards board){
    //add dates in matriz
    for(int r{0}; r< SIZE; ++r){
        for(int c{0};c<SIZE; ++c){

            std::cin >> board[r][c];
        }
    }
}
int main(void)
{


n_boards board;

add_dates(board);
    
    std::cout << "Board #"  << ": \n";
    print( board );
    std::cout << "Is valid? " << std::boolalpha
                << is_valid(board )
                << std::endl;

    std::cout << "\n";


    return 0;
}