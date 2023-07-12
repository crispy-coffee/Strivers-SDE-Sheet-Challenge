
vector<pair<int,int>> dir = {{-1,0}, {0,1}, {1,0}, {0,-1}};

void dfs(vector<vector<int>> &image, int x, int y, int oldcolor, int newcolor){

    image[x][y] = newcolor;

    for(auto d:dir){
        int newx = x+d.first;
        int newy = y+d.second;
        if(newx>=0 and newx<image.size() and newy>=0 and newy<image[0].size() and image[newx][newy] == oldcolor){
            dfs(image, newx, newy, oldcolor, newcolor);
        }
    }

}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newcolor)
{
    if(image[x][y] == newcolor)
        return image;

    int oldcolor = image[x][y];
    dfs(image, x, y, oldcolor, newcolor);
    return image;
}