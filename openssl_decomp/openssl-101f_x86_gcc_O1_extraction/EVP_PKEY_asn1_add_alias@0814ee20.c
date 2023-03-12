
int EVP_PKEY_asn1_add_alias(int to,int from)

{
  int *data;
  int iVar1;
  _STACK *st;
  uint uVar2;
  undefined4 *puVar3;
  byte bVar4;
  
  bVar4 = 0;
  data = (int *)CRYPTO_malloc(0x6c,"ameth_lib.c",0x124);
  if (data != (int *)0x0) {
    puVar3 = (undefined4 *)((uint)(data + 1) & 0xfffffffc);
    for (uVar2 = (uint)((int)data + (0x6c - (int)(undefined4 *)((uint)(data + 1) & 0xfffffffc))) >>
                 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
    }
    data[2] = 3;
    data[4] = 0;
    data[3] = 0;
    data[5] = 0;
    data[6] = 0;
    data[7] = 0;
    data[8] = 0;
    data[9] = 0;
    data[10] = 0;
    *data = from;
    data[0xb] = 0;
    data[0x18] = 0;
    data[0x17] = 0;
    data[0x19] = 0;
    data[1] = to;
    st = app_methods;
    data[0x1a] = 0;
    data[0xc] = 0;
    data[0xd] = 0;
    data[0xe] = 0;
    data[0xf] = 0;
    data[0x10] = 0;
    data[0x11] = 0;
    data[0x12] = 0;
    data[0x13] = 0;
    data[0x15] = 0;
    data[0x16] = 0;
    if (((st != (_STACK *)0x0) || (st = sk_new(ameth_cmp), app_methods = st, st != (_STACK *)0x0))
       && (iVar1 = sk_push(st,data), iVar1 != 0)) {
      sk_sort(app_methods);
      return 1;
    }
  }
  return 0;
}

