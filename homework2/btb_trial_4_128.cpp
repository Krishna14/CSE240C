#include <iostream> 
using namespace std; 
int main(void) {
uint64_t i;
uint64_t iter = 1000000;
for (i=0; i < iter; i++) {
__asm__ (
"clc\n"
"clc\n"
"mov $10, %eax\n"
"cmp $15, %eax\n"
"jle l780\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l780: jle l784\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l784: jle l788\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l788: jle l78c\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l78c: jle l790\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l790: jle l794\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l794: jle l798\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l798: jle l79c\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l79c: jle l7a0\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7a0: jle l7a4\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7a4: jle l7a8\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7a8: jle l7ac\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7ac: jle l7b0\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7b0: jle l7b4\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7b4: jle l7b8\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7b8: jle l7bc\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7bc: jle l7c0\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7c0: jle l7c4\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7c4: jle l7c8\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7c8: jle l7cc\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7cc: jle l7d0\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7d0: jle l7d4\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7d4: jle l7d8\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7d8: jle l7dc\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7dc: jle l7e0\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7e0: jle l7e4\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7e4: jle l7e8\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7e8: jle l7ec\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7ec: jle l7f0\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7f0: jle l7f4\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7f4: jle l7f8\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7f8: jle l7fc\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l7fc: jle l800\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l800: jle l804\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l804: jle l808\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l808: jle l80c\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l80c: jle l810\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l810: jle l814\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l814: jle l818\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l818: jle l81c\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l81c: jle l820\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l820: jle l824\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l824: jle l828\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l828: jle l82c\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l82c: jle l830\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l830: jle l834\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l834: jle l838\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l838: jle l83c\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l83c: jle l840\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l840: jle l844\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l844: jle l848\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l848: jle l84c\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l84c: jle l850\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l850: jle l854\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l854: jle l858\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l858: jle l85c\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l85c: jle l860\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l860: jle l864\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l864: jle l868\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l868: jle l86c\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l86c: jle l870\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l870: jle l874\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l874: jle l878\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l878: jle l87c\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l87c: jle l880\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l880: jle l884\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l884: jle l888\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l888: jle l88c\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l88c: jle l890\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l890: jle l894\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l894: jle l898\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l898: jle l89c\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l89c: jle l8a0\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8a0: jle l8a4\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8a4: jle l8a8\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8a8: jle l8ac\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8ac: jle l8b0\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8b0: jle l8b4\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8b4: jle l8b8\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8b8: jle l8bc\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8bc: jle l8c0\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8c0: jle l8c4\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8c4: jle l8c8\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8c8: jle l8cc\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8cc: jle l8d0\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8d0: jle l8d4\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8d4: jle l8d8\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8d8: jle l8dc\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8dc: jle l8e0\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8e0: jle l8e4\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8e4: jle l8e8\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8e8: jle l8ec\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8ec: jle l8f0\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8f0: jle l8f4\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8f4: jle l8f8\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8f8: jle l8fc\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l8fc: jle l900\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l900: jle l904\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l904: jle l908\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l908: jle l90c\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l90c: jle l910\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l910: jle l914\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l914: jle l918\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l918: jle l91c\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l91c: jle l920\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l920: jle l924\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l924: jle l928\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l928: jle l92c\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l92c: jle l930\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l930: jle l934\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l934: jle l938\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l938: jle l93c\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l93c: jle l940\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l940: jle l944\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l944: jle l948\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l948: jle l94c\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l94c: jle l950\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l950: jle l954\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l954: jle l958\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l958: jle l95c\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l95c: jle l960\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l960: jle l964\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l964: jle l968\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l968: jle l96c\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l96c: jle l970\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l970: jle l974\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l974: jle l978\n"
"clc\n"
"clc\n"
"clc\n"
"cmp $15, %eax\n"
"clc\n"
"l978: clc"
);
}
}
