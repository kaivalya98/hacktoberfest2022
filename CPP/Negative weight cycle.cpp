public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>dist(n,INT_MAX);
        dist[0]=0;
        for(int i=1;i<=n-1;i++){
            for(auto edge:edges){
                //cout<<dist[edge[0]+edge[2]<dist[edge[1]]]<<" ";
                if(dist[edge[0]+edge[2]<dist[edge[1]]]){
                    dist[edge[1]]=dist[edge[0]]+edge[2];
                }
            }
        }
    
        for(auto edge:edges){
            if(dist[edge[0]]+edge[2]<dist[edge[1]]){
                return 1;
            }
        }
        return 0;
	}
};
