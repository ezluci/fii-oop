int main()
{
    Painter p(10, 4);
    ((((p += 3_right) += 2_down) += 3_right) += 2_up) += 2_left;
    p.print();
    p(0, 3) = 'C';
    p(1, 3) = 'P';
    p(2, 3) = 'P';
    p.print();
    std::cout << "Area = " << (int)p << std::endl;
}
