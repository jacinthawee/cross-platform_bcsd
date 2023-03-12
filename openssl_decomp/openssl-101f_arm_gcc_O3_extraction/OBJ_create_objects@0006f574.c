
int OBJ_create_objects(BIO *in)

{
  ushort uVar1;
  int iVar2;
  ushort **ppuVar3;
  byte *pbVar4;
  byte *sn;
  ushort *puVar5;
  uint uVar6;
  byte *pbVar7;
  byte *ln;
  int iVar8;
  byte *pbVar9;
  byte abStack_229 [517];
  int local_24;
  
  ln = (byte *)0x0;
  iVar8 = 0;
  local_24 = __TMC_END__;
  while (iVar2 = BIO_gets(in,(char *)(abStack_229 + 1),0x200), 0 < iVar2) {
    abStack_229[iVar2] = 0;
    ppuVar3 = __ctype_b_loc();
    pbVar9 = (byte *)(uint)abStack_229[1];
    puVar5 = *ppuVar3;
    uVar6 = (uint)puVar5[(int)pbVar9];
    sn = pbVar9;
    pbVar7 = abStack_229 + 1;
    if (-1 < (int)(uVar6 << 0x1c)) break;
    while (((uVar6 & 0x800) != 0 || (sn == (byte *)0x2e))) {
      sn = (byte *)(uint)pbVar7[1];
      uVar6 = (uint)puVar5[(int)sn];
      pbVar7 = pbVar7 + 1;
    }
    if (sn == (byte *)0x0) {
LAB_0006f5fe:
      if (pbVar9 == (byte *)0x0) break;
    }
    else {
      uVar6 = (uint)pbVar7[1];
      sn = pbVar7 + 1;
      *pbVar7 = 0;
      uVar1 = puVar5[uVar6];
      while ((int)((uint)uVar1 << 0x12) < 0) {
        sn = sn + 1;
        uVar6 = (uint)*sn;
        uVar1 = puVar5[uVar6];
      }
      pbVar7 = sn;
      if (uVar6 == 0) {
        pbVar9 = (byte *)(uint)abStack_229[1];
        sn = (byte *)0x0;
        goto LAB_0006f5fe;
      }
      do {
        pbVar9 = pbVar7;
        pbVar7 = pbVar9 + 1;
        ln = (byte *)(uint)*pbVar7;
        if (ln == (byte *)0x0) goto LAB_0006f62a;
      } while (-1 < (int)((uint)puVar5[(int)ln] << 0x12));
      pbVar4 = (byte *)(uint)pbVar9[2];
      ln = pbVar9 + 2;
      *pbVar7 = 0;
      uVar1 = puVar5[(int)pbVar4];
      while ((int)((uint)uVar1 << 0x12) < 0) {
        ln = ln + 1;
        pbVar4 = (byte *)(uint)*ln;
        uVar1 = puVar5[(int)pbVar4];
      }
      if (pbVar4 == (byte *)0x0) {
        ln = pbVar4;
      }
LAB_0006f62a:
      if (abStack_229[1] == 0) break;
    }
    iVar2 = OBJ_create((char *)(abStack_229 + 1),(char *)sn,(char *)ln);
    if (iVar2 == 0) break;
    iVar8 = iVar8 + 1;
  }
  if (local_24 == __TMC_END__) {
    return iVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

