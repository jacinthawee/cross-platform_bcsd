
void SHA512_Transform(SHA512_CTX *c,uchar *data)

{
  _union_314 *p_Var1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  if (((uint)data & 7) == 0) {
    sha512_block_data_order(c,data,1);
    return;
  }
  puVar6 = (undefined4 *)(data + 0x80);
  p_Var1 = &c->u;
  do {
    uVar5 = *(undefined4 *)data;
    uVar4 = *(undefined4 *)((int)data + 4);
    uVar3 = *(undefined4 *)((int)data + 8);
    uVar2 = *(undefined4 *)((int)data + 0xc);
    data = (uchar *)((int)data + 0x10);
    *(undefined4 *)p_Var1 = uVar5;
    *(undefined4 *)((int)p_Var1 + 4) = uVar4;
    *(undefined4 *)((int)p_Var1 + 8) = uVar3;
    *(undefined4 *)((int)p_Var1 + 0xc) = uVar2;
    p_Var1 = (_union_314 *)((int)p_Var1 + 0x10);
  } while ((undefined4 *)data != puVar6);
  sha512_block_data_order(c,&c->u,1);
  return;
}

