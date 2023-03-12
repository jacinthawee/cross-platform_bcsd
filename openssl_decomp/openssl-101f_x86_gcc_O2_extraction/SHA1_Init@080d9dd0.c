
int SHA1_Init(SHA_CTX *c)

{
  uint uVar1;
  undefined4 *puVar2;
  
  c->num = 0;
  puVar2 = (undefined4 *)((uint)&c->h1 & 0xfffffffc);
  uVar1 = (uint)((int)c + (0x60 - (int)puVar2)) >> 2;
  for (; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  c->h0 = 0x67452301;
  c->h1 = 0xefcdab89;
  c->h2 = 0x98badcfe;
  c->h3 = 0x10325476;
  c->h4 = 0xc3d2e1f0;
  return 1;
}

