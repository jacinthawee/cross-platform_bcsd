
int SHA256_Init(SHA256_CTX *c)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)((uint)(c->h + 1) & 0xfffffffc);
  uVar1 = (uint)((int)c + (0x70 - (int)puVar2)) >> 2;
  for (; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  c->h[0] = 0x6a09e667;
  c->h[1] = 0xbb67ae85;
  c->h[2] = 0x3c6ef372;
  c->h[3] = 0xa54ff53a;
  c->h[4] = 0x510e527f;
  c->h[5] = 0x9b05688c;
  c->h[6] = 0x1f83d9ab;
  c->h[7] = 0x5be0cd19;
  c->md_len = 0x20;
  return 1;
}

