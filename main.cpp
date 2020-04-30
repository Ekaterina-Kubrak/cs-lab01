#include <iostream>
#include <vector>
using namespace std;

int main()
{
    size_t number_count;
    cerr << "Vvedite kolichestvo chisel:" << endl;
    cin >> number_count;
    vector<double>numbers(number_count);
    cerr << "Vvedite znachenie:" << endl;
    for(size_t i=0; i<number_count; i++)
    {
        cin >> numbers[i];
    }
    cerr << "Vvedite kolichestvo chisel:" << endl;
    size_t bin_count;
    cin >> bin_count;
    vector<size_t>bins(bin_count,0);
    double min = numbers[0];
    double max = numbers[0];
    for(double number:numbers)
    {
        if(number < min)
        {
            min = number;
        }
        else if(number > max)
        {
            max = number;
        }
    }
    for(double number:numbers)
    {
        size_t bin_index = (size_t)(number - min)*bin_count/(max - min);
        if(number == max)
        {
            bin_index--;
        }
        bins[bin_index]++;
    }
    const size_t MAX_W = 80, MAX_AST = MAX_W - 4;
    double koeff = 1;
    size_t max_count = 0;
    for(size_t bin:bins)
    {
        if(bin > max_count)
        {
            max_count = bin;
        }
    }
    if(max_count > MAX_AST)
    {
        koeff = static_cast<double>(MAX_AST)/max_count;
    }
    size_t sred = number_count/bin_count;
    for(size_t bin:bins)
    {
        if(bin < 10)
        {
            cout << " " << " ";
        }
        if(bin >=10 && bin < 100)
        {
            cout << " ";
        }
        if(bin > 100)
        {
            cout << "ERROR";
            break;
        }
        cout << bin << "|";
        size_t height = bin*koeff;
        if(height>=sred)
        {
            for(int i=0; i<sred; i++)
            {
                cout << "*";
            }
            for (size_t k = sred; k<height; k++)
            {
                cout << "+";
            }
        }
        else
        {
            for(int i=0; i<height; i++)
            {
                cout << "*";
            }
            for(size_t m = height; m < sred; m++)
            {
                cout << "-";
            }
        }
        cout << endl;
    }
    return 0;
}
