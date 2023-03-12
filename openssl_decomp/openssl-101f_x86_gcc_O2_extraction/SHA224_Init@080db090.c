
int SHA224_Init(SHA256_CTX *c)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)((uint)(c->h + 1) & 0xfffffffc);
  uVar1 = (uint)((int)c + (0x70 - (int)puVar2)) >> 2;
  for (; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  c->h[0] = 0xc1059ed8;
  c->h[1] = 0x367cd507;
  c->h[2] = 0x3070dd17;
  c->h[3] = 0xf70e5939;
  c->h[4] = 0xffc00b31;
  c->h[5] = 0x68581511;
  c->h[6] = 0x64f98fa7;
  c->h[7] = 0xbefa4fa4;
  c->md_len = 0x1c;
  return 1;
}

