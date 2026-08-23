class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       // Since the expected output is in vector (stack n vector are similar)
        vector<int> ans;
        for(int i : asteroids){
            //*IF 'while' condition is satisfied we don't need to add*
            bool yes = false;
    //the element in the top is "+ve" and present element is "-ve" 
    
    //!ans.empty() cuz if ans.back() for empty is "runtime error"          
            while(!ans.empty()&&ans.back()>0 && i<0){ 
                 //Top asteroid is smaller; destroy it and continue checking
                if(ans.back()<abs(i))  ans.pop_back();
                
                else{
                   // Both asteroids are equal; destroy top and incoming asteroid
                   if(ans.back()==abs(i)) ans.pop_back();
                   // Incoming asteroid is smaller; destroy incoming asteroid
                   yes=!yes;
                   break;
                }                 
              }
            // SEE why we used it
            if(!yes) ans.push_back(i);
        }
        return ans;
     }
};