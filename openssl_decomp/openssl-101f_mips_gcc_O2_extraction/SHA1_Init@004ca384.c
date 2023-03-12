
int SHA1_Init(SHA_CTX *c)

{
  undefined4 in_a3;
  
  (*(code *)PTR_memset_006aab00)(c,0,0x60,in_a3,&_gp);
  c->h0 = 0x67452301;
  c->h3 = 0x10325476;
  c->h1 = 0xefcdab89;
  c->h4 = 0xc3d2e1f0;
  c->h2 = 0x98badcfe;
  return 1;
}

