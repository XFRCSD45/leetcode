class Node{
    private : 
    Node* links[2];
    public :
    Node* get(int indx)
    {
        return links[indx];
    }
    bool containsKey(int indx)
    {
        return links[indx]!=NULL;
    }
    void put(int indx, Node* node)
    {
        links[indx]=node;
    }
};
class Trie
{
    private :
    
    Node* root;
     public:
    Trie()
    {
        root = new Node();
    }
   
    void insert(int num)
    {
        Node* node = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i)&1;
            if(!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node=node->get(bit);
        }
    }
    int getMax(int x)
    {
        Node* node = root;
        int maxi=0;
        for(int i=31;i>=0;i--)
        {
            int bit = (x>>i)&1;
            if(node->containsKey(1-bit))
            {
                maxi=maxi | (1<<i);
                node=node->get(1-bit);
            }else
            {
                node=node->get(bit);
            }
        }
        return maxi;
    }
};
class Solution {
public:

    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        for(auto it:nums)
        {
            trie->insert(it);
        }
        int ans=0;
        for(auto it:nums)
        {
            ans=max(ans, trie->getMax(it));
        }
        return ans;
    }
};