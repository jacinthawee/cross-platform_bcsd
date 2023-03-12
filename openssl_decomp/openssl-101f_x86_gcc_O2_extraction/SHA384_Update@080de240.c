
int SHA384_Update(SHA512_CTX *c,void *data,size_t len)

{
  ulonglong *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  byte bVar10;
  
  bVar10 = 0;
  if (len == 0) {
    return 1;
  }
  uVar5 = *(uint *)&c->Nl;
  uVar7 = *(uint *)((int)&c->Nl + 4);
  uVar3 = len * 8 + uVar5;
  uVar6 = (len >> 0x1d) + uVar7 + (uint)CARRY4(len * 8,uVar5);
  if ((uVar6 <= uVar7) && ((uVar6 < uVar7 || (uVar3 < uVar5)))) {
    puVar1 = &c->Nh;
    uVar5 = *(uint *)puVar1;
    *(int *)puVar1 = *(int *)puVar1 + 1;
    piVar2 = (int *)((int)&c->Nh + 4);
    *piVar2 = *piVar2 + (uint)(0xfffffffe < uVar5);
  }
  *(uint *)&c->Nl = uVar3;
  uVar5 = c->num;
  *(uint *)((int)&c->Nl + 4) = uVar6;
  if (uVar5 == 0) {
    if (len < 0x80) goto LAB_080de2f9;
LAB_080de392:
    sha512_block_data_order();
    data = (void *)((int)data + (len - (len & 0x7f)));
    len = len & 0x7f;
  }
  else {
    uVar7 = 0x80 - uVar5;
    if (len < uVar7) {
      memcpy((void *)((int)c->h + uVar5 + 0x50),data,len);
      c->num = c->num + len;
      return 1;
    }
    memcpy((void *)((int)c->h + uVar5 + 0x50),data,uVar7);
    c->num = 0;
    data = (void *)((int)data + uVar7);
    len = len - uVar7;
    sha512_block_data_order_constprop_1();
    if (0x7f < len) goto LAB_080de392;
  }
  if (len == 0) {
    return 1;
  }
LAB_080de2f9:
  if (len < 4) {
                    /* WARNING: Load size is inaccurate */
    if ((len != 0) && ((c->u).p[0] = *data, (len & 2) != 0)) {
      *(undefined2 *)((int)c->h + len + 0x4e) = *(undefined2 *)((int)data + (len - 2));
    }
  }
  else {
    puVar9 = (undefined4 *)((uint)((int)&c->u + 4U) & 0xfffffffc);
                    /* WARNING: Load size is inaccurate */
    iVar4 = (int)c + (0x50 - (int)puVar9);
    *(undefined4 *)&c->u = *data;
    *(undefined4 *)((int)c->h + len + 0x4c) = *(undefined4 *)((int)data + (len - 4));
    puVar8 = (undefined4 *)((int)data - iVar4);
    for (uVar5 = iVar4 + len >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar9 = *puVar8;
      puVar8 = puVar8 + (uint)bVar10 * -2 + 1;
      puVar9 = puVar9 + (uint)bVar10 * -2 + 1;
    }
  }
  c->num = len;
  return 1;
}

