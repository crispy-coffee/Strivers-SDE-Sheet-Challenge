bool findRedundantBrackets(string &s)
{

    stack<char> st;
    int i = 0;

    while (i < s.size())
    {

        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            st.push(s[i]);
            i++;
        }
        else
        {

            // Yaha tabhi aayenge jb opening bracket ho
            bool check = true; // ->assumne this is reduntant
            while (st.top() != '(')
            {
                if (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
                {
                    st.pop();
                    check = false;
                }
            }

            i++;
        }
    }

    if (st.empty())
    {
        return 0;
    }
}