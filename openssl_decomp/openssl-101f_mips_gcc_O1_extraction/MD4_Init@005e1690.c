
int MD4_Init(MD4_CTX *c)

{
  undefined4 in_a3;
  
  (*(code *)PTR_memset_006aab00)(c,0,0x5c,in_a3,&_gp);
  c->C = 0x98badcfe;
  c->A = 0x67452301;
  c->D = 0x10325476;
  c->B = 0xefcdab89;
  return 1;
}

