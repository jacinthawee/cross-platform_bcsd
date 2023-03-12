
int SHA512_Update(SHA512_CTX *c,void *data,size_t len)

{
  uint uVar1;
  _union_314 *p_Var2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  _union_314 *p_Var13;
  
  if (len == 0) {
    return 1;
  }
  uVar8 = *(uint *)((int)&c->Nl + 4);
  uVar4 = *(uint *)&c->Nl;
  uVar6 = len * 8 + uVar8;
  uVar1 = (uint)(uVar6 < len * 8) + (len >> 0x1d) + uVar4;
  if (uVar1 < uVar4) {
    uVar4 = *(uint *)((int)&c->Nh + 4);
LAB_004d0848:
    iVar9 = *(int *)&c->Nh;
    *(uint *)((int)&c->Nh + 4) = uVar4 + 1;
    *(uint *)&c->Nh = (uint)(uVar4 + 1 < uVar4) + iVar9;
  }
  else if ((uVar4 == uVar1) && (uVar6 < uVar8)) {
    uVar4 = *(uint *)((int)&c->Nh + 4);
    goto LAB_004d0848;
  }
  uVar4 = c->num;
  p_Var13 = &c->u;
  *(uint *)&c->Nl = uVar1;
  *(uint *)((int)&c->Nl + 4) = uVar6;
  if (uVar4 == 0) {
    if (len < 0x80) goto LAB_004d096c;
    puVar12 = (undefined4 *)data;
    uVar1 = len;
    if (((uint)data & 7) == 0) {
      uVar4 = len >> 7;
      goto LAB_004d0a28;
    }
LAB_004d08d4:
    do {
      puVar11 = (undefined4 *)((int)data + 0x80);
      p_Var2 = p_Var13;
      do {
                    /* WARNING: Load size is inaccurate */
        uVar10 = *data;
        uVar7 = *(undefined4 *)((int)data + 4);
        uVar5 = *(undefined4 *)((int)data + 8);
        uVar3 = *(undefined4 *)((int)data + 0xc);
        data = (void *)((int)data + 0x10);
        *(undefined4 *)p_Var2 = uVar10;
        *(undefined4 *)((int)p_Var2 + 4) = uVar7;
        *(undefined4 *)((int)p_Var2 + 8) = uVar5;
        *(undefined4 *)((int)p_Var2 + 0xc) = uVar3;
        p_Var2 = (_union_314 *)((int)p_Var2 + 0x10);
      } while ((undefined4 *)data != puVar11);
      len = len - 0x80;
      sha512_block_data_order(c,p_Var13,1);
    } while (0x7f < len);
    len = uVar1 & 0x7f;
    data = puVar12 + ((uVar1 - 0x80 >> 7) + 1) * 0x20;
  }
  else {
    uVar1 = 0x80 - uVar4;
    if (len < uVar1) {
      (*(code *)PTR_memcpy_006a9aec)((int)p_Var13 + uVar4,data,len);
      c->num = c->num + len;
      return 1;
    }
    (*(code *)PTR_memcpy_006a9aec)((int)p_Var13 + uVar4,data,uVar1);
    len = len - uVar1;
    c->num = 0;
    sha512_block_data_order(c,p_Var13,1);
    data = (void *)((int)data + uVar1);
    if (0x7f < len) {
      uVar4 = len >> 7;
      puVar12 = (undefined4 *)data;
      uVar1 = len;
      if (((uint)data & 7) != 0) goto LAB_004d08d4;
LAB_004d0a28:
      sha512_block_data_order(c,data,uVar4);
      data = (void *)((int)data + (len - (len & 0x7f)));
      len = len & 0x7f;
    }
  }
  if (len == 0) {
    return 1;
  }
LAB_004d096c:
  (*(code *)PTR_memcpy_006a9aec)(p_Var13,data,len);
  c->num = len;
  return 1;
}

