#pragma once
#include <string>
#include <cstdint>

namespace cryptolab{

inline std::string zhuanhuan(uint32_t num){
std::string a="";
for(int i=0;i<32;i++){
if(num&(1u<<31)){
a+='1';
}else{
a+='0';
}
num=num<<1;
}
return a;
}
}
