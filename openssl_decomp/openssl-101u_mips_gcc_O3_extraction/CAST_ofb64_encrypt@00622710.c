
void CAST_ofb64_encrypt(uchar *in,uchar *out,long length,CAST_KEY *schedule,uchar *ivec,int *num)

{
  byte *pbVar1;
  byte bVar2;
  uint **ppuVar3;
  undefined *puVar4;
  uint **ppuVar5;
  uint **ppuVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  long lVar11;
  int iVar12;
  uint local_3c;
  uint local_38;
  byte local_34 [4];
  undefined local_30;
  undefined local_2f;
  undefined local_2e;
  undefined local_2d;
  int local_2c;
  
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  local_3c = *(uint *)ivec;
  local_38 = *(uint *)(ivec + 4);
  uVar10 = *num;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_34[3] = (char)local_3c;
  local_34[0] = (byte)(local_3c >> 0x18);
  local_34[1] = (char)(local_3c >> 0x10);
  uVar9 = local_38 >> 0x10;
  local_34[2] = (char)(local_3c >> 8);
  local_30 = (char)(local_38 >> 0x18);
  local_2f = (char)(local_38 >> 0x10);
  local_2e = (char)(local_38 >> 8);
  local_2d = (char)local_38;
  if (length != 0) {
    iVar12 = 0;
    lVar11 = length;
    do {
      if (uVar10 == 0) {
        iVar12 = iVar12 + 1;
        (*(code *)PTR_CAST_encrypt_006a98cc)(&local_3c,schedule);
        length = local_3c >> 0x10;
        local_34[3] = (char)local_3c;
        uVar9 = local_38 >> 0x18;
        local_2d = (char)local_38;
        local_34[0] = (byte)(local_3c >> 0x18);
        local_34[1] = (char)(local_3c >> 0x10);
        local_30 = (char)(local_38 >> 0x18);
        local_34[2] = (char)(local_3c >> 8);
        local_2f = (char)(local_38 >> 0x10);
        local_2e = (char)(local_38 >> 8);
      }
      bVar2 = *in;
      lVar11 = lVar11 + -1;
      pbVar1 = local_34 + uVar10;
      in = in + 1;
      uVar10 = uVar10 + 1 & 7;
      *out = bVar2 ^ *pbVar1;
      out = out + 1;
    } while (lVar11 != 0);
    if (iVar12 != 0) {
      length = local_3c >> 0x10;
      ivec[3] = (uchar)local_3c;
      uVar9 = local_38 >> 0x18;
      ivec[7] = (uchar)local_38;
      *ivec = (uchar)(local_3c >> 0x18);
      ivec[1] = (uchar)(local_3c >> 0x10);
      ivec[4] = (uchar)(local_38 >> 0x18);
      ivec[2] = (uchar)(local_3c >> 8);
      ivec[5] = (uchar)(local_38 >> 0x10);
      ivec[6] = (uchar)(local_38 >> 8);
    }
  }
  iVar12 = *(int *)puVar4;
  *num = uVar10;
  if (local_2c == iVar12) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  (*(code *)PTR_BN_CTX_start_006a8528)(length);
  ppuVar5 = (uint **)(*(code *)PTR_BN_CTX_get_006a852c)(length);
  ppuVar6 = (uint **)(*(code *)PTR_BN_CTX_get_006a852c)(length);
  if (ppuVar6 == (uint **)0x0) {
    (*(code *)PTR_BN_CTX_end_006a8530)(length);
    return;
  }
  iVar12 = (*(code *)PTR_BN_copy_006a8450)(ppuVar5,num);
  if (iVar12 == 0) {
LAB_00622a04:
    (*(code *)PTR_BN_CTX_end_006a8530)(length);
    return;
  }
  iVar12 = (*(code *)PTR_BN_copy_006a8450)(ppuVar6,uVar9);
  if (iVar12 != 0) {
    if (ppuVar6[1] != (uint *)0x0) {
      if (((int)ppuVar5[1] < 1) || (iVar12 = 0, (**ppuVar5 & 1) == 0)) {
        if (((int)ppuVar6[1] < 1) || ((**ppuVar6 & 1) == 0)) goto LAB_006229cc;
        iVar12 = 0;
      }
      while (iVar7 = (*(code *)PTR_BN_is_bit_set_006a8538)(ppuVar6,iVar12), iVar7 == 0) {
        iVar12 = iVar12 + 1;
      }
      iVar12 = (*(code *)PTR_BN_rshift_006a85d4)(ppuVar6,ppuVar6,iVar12);
      if (iVar12 != 0) {
        puVar8 = ppuVar5[1];
        if (ppuVar6[3] != (uint *)0x0) {
          ppuVar6[3] = (uint *)0x0;
        }
        while (ppuVar3 = ppuVar5, puVar8 != (uint *)0x0) {
          iVar12 = 0;
          while (iVar7 = (*(code *)PTR_BN_is_bit_set_006a8538)(ppuVar3,iVar12), iVar7 == 0) {
            iVar12 = iVar12 + 1;
          }
          iVar12 = (*(code *)PTR_BN_rshift_006a85d4)(ppuVar3,ppuVar3,iVar12);
          if (iVar12 == 0) goto LAB_00622a04;
          iVar12 = (*(code *)PTR_BN_nnmod_006a8548)(ppuVar6,ppuVar6,ppuVar3,length);
          if (iVar12 == 0) break;
          puVar8 = ppuVar6[1];
          ppuVar3[3] = (uint *)0x0;
          ppuVar5 = ppuVar6;
          ppuVar6 = ppuVar3;
        }
      }
    }
  }
LAB_006229cc:
  (*(code *)PTR_BN_CTX_end_006a8530)(length);
  return;
}

