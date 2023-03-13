
int RIPEMD160_Init(RIPEMD160_CTX *c)

{
  undefined4 in_a3;
  
  (*(code *)PTR_memset_006a99f4)(c,0,0x60,in_a3,&_gp);
  c->A = 0x67452301;
  c->D = 0x10325476;
  c->B = 0xefcdab89;
  c->E = 0xc3d2e1f0;
  c->C = 0x98badcfe;
  return 1;
}

