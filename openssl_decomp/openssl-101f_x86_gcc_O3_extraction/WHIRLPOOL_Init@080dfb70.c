
int WHIRLPOOL_Init(WHIRLPOOL_CTX *c)

{
  uint uVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)&c->H = 0;
  c->bitlen[7] = 0;
  puVar2 = (undefined4 *)((uint)((int)&c->H + 4U) & 0xfffffffc);
  uVar1 = (uint)((int)c + (0xa4 - (int)puVar2)) >> 2;
  for (; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return 1;
}

