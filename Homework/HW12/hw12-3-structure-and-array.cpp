/*
    ผู้ใช้กรอกข้อมูลพนักงานในบริษัท โดยจะกรอกข้อมูล ชื่อ, เงินเดือน, อายุการทำงาน ของแต่ละคน โดยเมื่อผู้ใช้กรอกตัว n จะถือเป็นการหยุดโปรแกรมและทำการแสดงข้อมูลเงินเดือนเฉลี่ยของพนักงานในบริษัท และเงินเดือนของทุกคนรวมกันที่ผู้บริหารต้องจ่าย และแสดงคนที่อายุงานเยอะที่สุดพร้อมระบุ ชื่อ เงินเดือน และอายุงาน ของคนๆ นั้น
    
    Test case:
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Yorn
        Salary (Bath/Month) : 
            15000
        Duration (Year) : 
            4
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Van
        Salary (Bath/Month) : 
            14550
        Duration (Year) : 
            2
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Thane
        Salary (Bath/Month) : 
            22500
        Duration (Year) : 
            8
        Do you want to Enter Employee Information? (y/n) : 
            n
    Output:
        Average of Salary : 17,350.00 Bath
        Payment of every month : 52,050.00 Bath
        ----------------------------------------
        ** Most duration in this business **
        Name : Thane (8 Years)
        Salary : 22,500.00 Bath

*/

//TODO: #21 output money should in decimal format (eg. 120,200,340.42).

#include <stdio.h>

struct data {
    char name[50] ;
    float money ; 
    int year ;
} ;

int main() {
    char ask ;
    int n = 0 ;
    do {
        data group[50] ;

        printf( "Do you want to Enter Employee Information? (y/n) : \n" ) ;
        scanf( " %c", &ask ) ;

        if( ask == 'n' || ask == 'N'){
            for( int i = 0 ; i < n ; i++ ) {
                //หาคนรวย
                for( int j = i + 1 ; j < n ; j++ ) {
                    if( group[i].money < group[j].money ) {
                        struct data total = group[i] ;
                        group[i] = group[j] ;
                        group[j] = total ;
                    }
                }
            }

            int Salary = 0 ;
            for( int i = 0 ; i < n ; i++ ) {
            Salary += group[i].money;
            }
            printf( "Average of Salary : %d Bath\n", Salary / n) ;
            printf( "Payment of every month : %d Bath\n", Salary ) ;
            printf( "----------------------------------------\n" ) ;
            printf( "** Most duration in this business **\n" ) ;
            printf( "Name : %s (%d Years)\n", group[0].name, group[0].year ) ;
            printf( "Salary : %.2f Bath\n", group[0].money ) ;
            break ;
        }

        if ( ask == 'y' || ask == 'Y') {
            printf( "%d" , n ) ;
            printf( "----\n" ) ;
            printf( "Employee Name : \n" ) ;
            scanf( "%s", group[n].name ) ;
            printf( "Salary (Bath/Month) : \n" ) ;
            scanf( "%f", &group[n].money ) ;
            printf( "Duration (Year) : \n" ) ;
            scanf( "%d", &group[n].year ) ;
            n = n + 1 ;
        }
    } while ( ask != 'n' && ask != 'N' ) ;

    return 0 ;
}
