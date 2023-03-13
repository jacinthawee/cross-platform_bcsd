
void EVP_CIPHER_CTX_init(EVP_CIPHER_CTX *a)

{
  uint uVar1;
  undefined4 *puVar2;
  
  a->cipher = (EVP_CIPHER *)0x0;
  *(undefined4 *)(a->final + 0x1c) = 0;
  puVar2 = (undefined4 *)((uint)&a->engine & 0xfffffffc);
  uVar1 = (uint)((int)a + (0x8c - (int)puVar2)) >> 2;
  for (; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}

