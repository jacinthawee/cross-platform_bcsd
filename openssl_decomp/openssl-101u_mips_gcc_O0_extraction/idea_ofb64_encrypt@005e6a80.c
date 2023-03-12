
void idea_ofb64_encrypt(uchar *in,uchar *out,long length,IDEA_KEY_SCHEDULE *ks,uchar *iv,int *num)

{
  byte *pbVar1;
  byte bVar2;
  undefined *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_3c;
  uint local_38;
  byte local_34 [4];
  undefined local_30;
  undefined local_2f;
  undefined local_2e;
  undefined local_2d;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_3c = *(undefined4 *)iv;
  local_38 = *(uint *)(iv + 4);
  uVar5 = *num;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_34[3] = (char)local_3c;
  local_34[0] = (byte)((uint)local_3c >> 0x18);
  uVar4 = local_38 >> 0x18;
  local_34[1] = (char)((uint)local_3c >> 0x10);
  local_34[2] = (char)((uint)local_3c >> 8);
  local_30 = (char)(local_38 >> 0x18);
  local_2f = (char)(local_38 >> 0x10);
  local_2e = (char)(local_38 >> 8);
  local_2d = (char)local_38;
  if (length != 0) {
    iVar6 = 0;
    do {
      if (uVar5 == 0) {
        iVar6 = iVar6 + 1;
        (*(code *)PTR_idea_encrypt_006a84e8)(&local_3c,ks);
        local_34[3] = (char)local_3c;
        local_2d = (char)local_38;
        local_34[0] = (byte)((uint)local_3c >> 0x18);
        local_34[1] = (char)((uint)local_3c >> 0x10);
        local_30 = (char)(local_38 >> 0x18);
        local_34[2] = (char)((uint)local_3c >> 8);
        local_2f = (char)(local_38 >> 0x10);
        local_2e = (char)(local_38 >> 8);
      }
      bVar2 = *in;
      length = length + -1;
      pbVar1 = local_34 + uVar5;
      in = in + 1;
      uVar5 = uVar5 + 1 & 7;
      *out = bVar2 ^ *pbVar1;
      out = out + 1;
    } while (length != 0);
    if (iVar6 != 0) {
      iv[3] = (uchar)local_3c;
      iv[7] = (uchar)local_38;
      *iv = (uchar)((uint)local_3c >> 0x18);
      iv[1] = (uchar)((uint)local_3c >> 0x10);
      iv[4] = (uchar)(local_38 >> 0x18);
      iv[2] = (uchar)((uint)local_3c >> 8);
      iv[5] = (uchar)(local_38 >> 0x10);
      iv[6] = (uchar)(local_38 >> 8);
    }
  }
  iVar6 = *(int *)puVar3;
  *num = uVar5;
  if (local_2c == iVar6) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (uVar4 != 1) {
                    /* WARNING: Could not recover jumptable at 0x005e6c84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_Camellia_decrypt_006a8514)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x005e6c90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_Camellia_encrypt_006a8518)();
  return;
}

