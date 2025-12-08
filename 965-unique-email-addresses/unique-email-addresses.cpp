class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string, unordered_set<string>>domains;
        int numberOfUniqueEmails = 0 ;
        for(string email : emails){
            string editedEmail, domain;
            for(int i = 0 ; i < email.size() ; i ++){
                if(email[i] == '+'){
                    while(email[i] != '@') i ++ ;
                }
                if(email[i] == '@'){
                    domain = email.substr(i + 1) ;
                    break ;
                }
                if(email[i] != '.') editedEmail.push_back(email[i]) ;
            }
            if(!domains[domain].contains(editedEmail)) numberOfUniqueEmails ++ ;
            domains[domain].insert(editedEmail) ;
        }
        return numberOfUniqueEmails ;
    }
};