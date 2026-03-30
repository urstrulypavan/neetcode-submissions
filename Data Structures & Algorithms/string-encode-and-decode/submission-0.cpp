class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(auto &str : strs){
            encoded += std::to_string(str.size());
            encoded += '/';
            encoded += str;
        }
        return encoded;
    }
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while(i < s.size()){
            size_t delimiter_pos = s.find('/', i);
            if (delimiter_pos == std::string::npos) {
            break; 
            }
            std::string str_size = s.substr(i, delimiter_pos-i);
            int actual_size = stoi(str_size);
            std::string word = s.substr(delimiter_pos + 1, actual_size);
            decoded.push_back(word);
            i = delimiter_pos  + 1 + actual_size;
        }
        return decoded;
    }
};
