
int SHA512_Init(SHA512_CTX *c)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  uVar5 = DAT_000715bc;
  uVar4 = DAT_000715b8;
  uVar3 = DAT_000715b4;
  uVar2 = DAT_000715b0;
  uVar1 = DAT_000715ac;
  *(undefined4 *)c->h = DAT_000715a8;
  *(undefined4 *)((int)c->h + 4) = uVar1;
  uVar6 = DAT_000715c4;
  uVar1 = DAT_000715c0;
  *(undefined4 *)(c->h + 1) = uVar2;
  *(undefined4 *)((int)c->h + 0xc) = uVar3;
  uVar3 = DAT_000715cc;
  uVar2 = DAT_000715c8;
  *(undefined4 *)(c->h + 2) = uVar4;
  *(undefined4 *)((int)c->h + 0x14) = uVar5;
  uVar5 = DAT_000715d4;
  uVar4 = DAT_000715d0;
  *(undefined4 *)(c->h + 3) = uVar1;
  *(undefined4 *)((int)c->h + 0x1c) = uVar6;
  uVar8 = DAT_000715e4;
  uVar7 = DAT_000715e0;
  uVar6 = DAT_000715dc;
  uVar1 = DAT_000715d8;
  *(undefined4 *)(c->h + 5) = uVar2;
  *(undefined4 *)((int)c->h + 0x2c) = uVar3;
  *(undefined4 *)(c->h + 4) = uVar1;
  *(undefined4 *)((int)c->h + 0x24) = uVar6;
  *(undefined4 *)(c->h + 6) = uVar4;
  *(undefined4 *)((int)c->h + 0x34) = uVar5;
  *(undefined4 *)(c->h + 7) = uVar7;
  *(undefined4 *)((int)c->h + 0x3c) = uVar8;
  c->num = 0;
  c->md_len = 0x40;
  *(undefined4 *)&c->Nl = 0;
  *(undefined4 *)((int)&c->Nl + 4) = 0;
  *(undefined4 *)&c->Nh = 0;
  *(undefined4 *)((int)&c->Nh + 4) = 0;
  return 1;
}

