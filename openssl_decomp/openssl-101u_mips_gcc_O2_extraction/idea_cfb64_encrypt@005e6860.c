
void idea_cfb64_encrypt(uchar *in,uchar *out,long length,IDEA_KEY_SCHEDULE *ks,uchar *iv,int *num,
                       int enc)

{
  byte bVar1;
  byte bVar2;
  undefined *puVar3;
  int iVar4;
  byte *pbVar5;
  IDEA_KEY_SCHEDULE *pIVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  uint *unaff_s8;
  undefined4 uStack_8c;
  uint uStack_88;
  byte abStack_84 [4];
  undefined uStack_80;
  undefined uStack_7f;
  undefined uStack_7e;
  undefined uStack_7d;
  int iStack_7c;
  uint uStack_78;
  uchar *puStack_74;
  IDEA_KEY_SCHEDULE *pIStack_70;
  int *piStack_6c;
  undefined *puStack_68;
  int iStack_64;
  byte *pbStack_60;
  byte *pbStack_5c;
  uint *puStack_58;
  code *pcStack_54;
  undefined4 *local_40;
  uint *puStack_3c;
  uint local_34;
  uint local_30;
  int local_2c;
  
  puStack_68 = PTR___stack_chk_guard_006a9ae8;
  puVar10 = (undefined4 *)&_gp;
  local_40 = (undefined4 *)&_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_78 = *num;
  pIVar6 = ks;
  iStack_64 = length;
  pbStack_60 = in;
  pbStack_5c = out;
  if (enc == 0) {
    unaff_s8 = &local_34;
    pbVar9 = out;
    if (length != 0) {
      do {
        out = (uchar *)ks;
        if (uStack_78 == 0) {
          local_34 = *(uint *)iv;
          local_30 = *(uint *)(iv + 4);
          (**(code **)((int)puVar10 + -0x68f8))(unaff_s8);
          length = local_34 >> 0x10;
          iv[3] = (uchar)local_34;
          out = (uchar *)(local_30 >> 0x18);
          iv[7] = (uchar)local_30;
          *iv = (uchar)(local_34 >> 0x18);
          iv[1] = (uchar)(local_34 >> 0x10);
          iv[4] = (uchar)(local_30 >> 0x18);
          iv[2] = (uchar)(local_34 >> 8);
          iv[5] = (uchar)(local_30 >> 0x10);
          iv[6] = (uchar)(local_30 >> 8);
          puVar10 = local_40;
        }
        bVar1 = *pbStack_60;
        bVar2 = iv[uStack_78];
        in = (uchar *)(uint)bVar2;
        iStack_64 = iStack_64 + -1;
        iv[uStack_78] = bVar1;
        pbStack_60 = pbStack_60 + 1;
        uStack_78 = uStack_78 + 1 & 7;
        *pbVar9 = bVar1 ^ bVar2;
        pbStack_5c = pbVar9 + 1;
        pbVar9 = pbVar9 + 1;
      } while (iStack_64 != 0);
    }
  }
  else if (length != 0) {
    unaff_s8 = &local_34;
    pbVar9 = out;
    do {
      if (uStack_78 == 0) {
        local_34 = *(uint *)iv;
        local_30 = *(uint *)(iv + 4);
        (*(code *)local_40[-0x1a3e])(unaff_s8,ks);
        length = local_34 >> 0x10;
        iv[3] = (uchar)local_34;
        out = (uchar *)(local_30 >> 0x18);
        iv[7] = (uchar)local_30;
        *iv = (uchar)(local_34 >> 0x18);
        iv[1] = (uchar)(local_34 >> 0x10);
        iv[4] = (uchar)(local_30 >> 0x18);
        iv[2] = (uchar)(local_34 >> 8);
        iv[5] = (uchar)(local_30 >> 0x10);
        iv[6] = (uchar)(local_30 >> 8);
      }
      pbVar5 = iv + uStack_78;
      bVar1 = *pbStack_60;
      pbStack_5c = pbVar9 + 1;
      bVar2 = *pbVar5;
      in = (uchar *)(uint)bVar2;
      iStack_64 = iStack_64 + -1;
      pbStack_60 = pbStack_60 + 1;
      uStack_78 = uStack_78 + 1 & 7;
      bVar1 = bVar1 ^ bVar2;
      *pbVar9 = bVar1;
      *pbVar5 = bVar1;
      puVar10 = local_40;
      pbVar9 = pbStack_5c;
    } while (iStack_64 != 0);
  }
  iVar4 = *(int *)puStack_68;
  *num = uStack_78;
  if (local_2c == iVar4) {
    return;
  }
  pcStack_54 = idea_ofb64_encrypt;
  (*(code *)puVar10[-0x14cc])();
  puVar10 = local_40;
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  pIStack_70 = ks;
  puStack_58 = unaff_s8;
  piStack_6c = num;
  puStack_74 = iv;
  uStack_8c = *local_40;
  uStack_88 = local_40[1];
  uVar8 = *puStack_3c;
  iStack_7c = *(int *)PTR___stack_chk_guard_006a9ae8;
  abStack_84[3] = (char)uStack_8c;
  abStack_84[0] = (byte)((uint)uStack_8c >> 0x18);
  uVar7 = uStack_88 >> 0x18;
  abStack_84[1] = (char)((uint)uStack_8c >> 0x10);
  abStack_84[2] = (char)((uint)uStack_8c >> 8);
  uStack_80 = (char)(uStack_88 >> 0x18);
  uStack_7f = (char)(uStack_88 >> 0x10);
  uStack_7e = (char)(uStack_88 >> 8);
  uStack_7d = (char)uStack_88;
  if (length != 0) {
    iVar4 = 0;
    do {
      if (uVar8 == 0) {
        iVar4 = iVar4 + 1;
        (*(code *)PTR_idea_encrypt_006a84e8)(&uStack_8c,pIVar6);
        abStack_84[3] = (char)uStack_8c;
        uStack_7d = (char)uStack_88;
        abStack_84[0] = (byte)((uint)uStack_8c >> 0x18);
        abStack_84[1] = (char)((uint)uStack_8c >> 0x10);
        uStack_80 = (char)(uStack_88 >> 0x18);
        abStack_84[2] = (char)((uint)uStack_8c >> 8);
        uStack_7f = (char)(uStack_88 >> 0x10);
        uStack_7e = (char)(uStack_88 >> 8);
      }
      bVar1 = *in;
      length = length - 1;
      pbVar9 = abStack_84 + uVar8;
      in = in + 1;
      uVar8 = uVar8 + 1 & 7;
      *(byte *)*(uint (*) [6])out = bVar1 ^ *pbVar9;
      out = (uchar *)((int)*(uint (*) [6])out + 1);
    } while (length != 0);
    if (iVar4 != 0) {
      *(char *)((int)puVar10 + 3) = (char)uStack_8c;
      *(char *)((int)puVar10 + 7) = (char)uStack_88;
      *(char *)puVar10 = (char)((uint)uStack_8c >> 0x18);
      *(char *)((int)puVar10 + 1) = (char)((uint)uStack_8c >> 0x10);
      *(char *)(puVar10 + 1) = (char)(uStack_88 >> 0x18);
      *(char *)((int)puVar10 + 2) = (char)((uint)uStack_8c >> 8);
      *(char *)((int)puVar10 + 5) = (char)(uStack_88 >> 0x10);
      *(char *)((int)puVar10 + 6) = (char)(uStack_88 >> 8);
    }
  }
  iVar4 = *(int *)puVar3;
  *puStack_3c = uVar8;
  if (iStack_7c != iVar4) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    if (uVar7 == 1) {
                    /* WARNING: Could not recover jumptable at 0x005e6c90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_Camellia_encrypt_006a8518)();
      return;
    }
                    /* WARNING: Could not recover jumptable at 0x005e6c84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_Camellia_decrypt_006a8514)();
    return;
  }
  return;
}

