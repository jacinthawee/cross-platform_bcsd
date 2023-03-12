
int SHA384_Init(SHA512_CTX *c)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  uVar5 = DAT_0006f1fc;
  uVar4 = DAT_0006f1f8;
  uVar3 = DAT_0006f1f4;
  uVar2 = DAT_0006f1f0;
  uVar1 = DAT_0006f1ec;
  *(undefined4 *)c->h = DAT_0006f1e8;
  *(undefined4 *)((int)c->h + 4) = uVar1;
  uVar6 = DAT_0006f204;
  uVar1 = DAT_0006f200;
  *(undefined4 *)(c->h + 1) = uVar2;
  *(undefined4 *)((int)c->h + 0xc) = uVar3;
  uVar3 = DAT_0006f20c;
  uVar2 = DAT_0006f208;
  *(undefined4 *)(c->h + 2) = uVar4;
  *(undefined4 *)((int)c->h + 0x14) = uVar5;
  uVar5 = DAT_0006f214;
  uVar4 = DAT_0006f210;
  *(undefined4 *)(c->h + 3) = uVar1;
  *(undefined4 *)((int)c->h + 0x1c) = uVar6;
  uVar8 = DAT_0006f224;
  uVar7 = DAT_0006f220;
  uVar6 = DAT_0006f21c;
  uVar1 = DAT_0006f218;
  *(undefined4 *)(c->h + 5) = uVar2;
  *(undefined4 *)((int)c->h + 0x2c) = uVar3;
  *(undefined4 *)(c->h + 4) = uVar1;
  *(undefined4 *)((int)c->h + 0x24) = uVar6;
  *(undefined4 *)(c->h + 6) = uVar4;
  *(undefined4 *)((int)c->h + 0x34) = uVar5;
  *(undefined4 *)(c->h + 7) = uVar7;
  *(undefined4 *)((int)c->h + 0x3c) = uVar8;
  c->num = 0;
  c->md_len = 0x30;
  *(undefined4 *)&c->Nl = 0;
  *(undefined4 *)((int)&c->Nl + 4) = 0;
  *(undefined4 *)&c->Nh = 0;
  *(undefined4 *)((int)&c->Nh + 4) = 0;
  return 1;
}

