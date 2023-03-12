
int do_dtls1_write(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5
                  )

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined *puVar7;
  undefined *puVar8;
  int local_30;
  
  if (*(int *)(param_1[0x16] + 0x108) != 0) {
    OpenSSLDie("d1_pkt.c",0x60f,"0");
    iVar6 = ssl3_write_pending(param_1,param_2,param_3,param_4);
    return iVar6;
  }
  if ((*(int *)(param_1[0x16] + 0x18c) != 0) &&
     (iVar6 = (**(code **)(param_1[2] + 0x3c))(), iVar6 < 1)) {
    return iVar6;
  }
  if ((param_4 == 0) && (param_5 == 0)) {
    return 0;
  }
  iVar6 = param_1[0x16];
  if (((param_1[0x30] == 0) || (param_1[0x23] == 0)) ||
     (iVar1 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(param_1[0x24]), iVar1 == 0)) {
    iVar1 = 0;
  }
  else {
    uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(param_1[0x24]);
    iVar1 = (*(code *)PTR_EVP_MD_size_006a7e3c)(uVar2);
    if (iVar1 < 0) {
      return -1;
    }
  }
  puVar7 = *(undefined **)(iVar6 + 0xfc);
  *puVar7 = (char)param_2;
  uVar2 = *param_1;
  *(undefined4 *)(iVar6 + 0x130) = param_2;
  puVar7[1] = (char)((uint)uVar2 >> 8);
  puVar7[2] = (char)*param_1;
  puVar8 = puVar7 + 0xd;
  if (((undefined4 *)param_1[0x23] == (undefined4 *)0x0) ||
     (uVar3 = (*(code *)PTR_EVP_CIPHER_flags_006a7544)(*(undefined4 *)param_1[0x23]),
     (uVar3 & 2) == 0)) {
    local_30 = 0;
  }
  else {
    local_30 = (*(code *)PTR_EVP_CIPHER_block_size_006a80f0)(*(undefined4 *)param_1[0x23]);
  }
  iVar4 = param_1[0x25];
  *(int *)(iVar6 + 0x134) = param_4;
  *(undefined4 *)(iVar6 + 0x140) = param_3;
  *(undefined **)(iVar6 + 0x13c) = puVar8 + local_30;
  if (iVar4 == 0) {
    (*(code *)PTR_memcpy_006a9aec)(puVar8 + local_30,param_3,param_4);
    *(undefined4 *)(iVar6 + 0x140) = *(undefined4 *)(iVar6 + 0x13c);
  }
  else {
    iVar4 = ssl3_do_compress(param_1);
    if (iVar4 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xf5,0x8d,"d1_pkt.c",0x676);
      return -1;
    }
  }
  if (iVar1 != 0) {
    iVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 4))
                      (param_1,puVar8 + local_30 + *(int *)(iVar6 + 0x134),1);
    if (iVar4 < 0) {
      return -1;
    }
    *(int *)(iVar6 + 0x134) = *(int *)(iVar6 + 0x134) + iVar1;
  }
  *(undefined **)(iVar6 + 0x140) = puVar8;
  *(undefined **)(iVar6 + 0x13c) = puVar8;
  if (local_30 != 0) {
    iVar1 = (*(code *)PTR_RAND_bytes_006a7574)(puVar8,local_30);
    if (iVar1 < 1) {
      return -1;
    }
    *(int *)(iVar6 + 0x134) = *(int *)(iVar6 + 0x134) + local_30;
  }
  iVar1 = (***(code ***)(param_1[2] + 100))(param_1,1);
  if (iVar1 < 1) {
    return -1;
  }
  puVar7[3] = (char)((ushort)*(undefined2 *)(param_1[0x17] + 0x20a) >> 8);
  puVar7[4] = (char)*(undefined2 *)(param_1[0x17] + 0x20a);
  iVar1 = param_1[0x16];
  uVar5 = *(uint *)(iVar1 + 0x56);
  puVar8 = puVar7 + 5;
  uVar3 = (uint)puVar8 & 3;
  *(uint *)(puVar8 + -uVar3) =
       *(uint *)(puVar8 + -uVar3) & -1 << (4 - uVar3) * 8 | uVar5 >> uVar3 * 8;
  puVar8 = puVar7 + 8;
  uVar3 = (uint)puVar8 & 3;
  *(uint *)(puVar8 + -uVar3) =
       *(uint *)(puVar8 + -uVar3) & 0xffffffffU >> (uVar3 + 1) * 8 | uVar5 << (3 - uVar3) * 8;
  puVar7[9] = *(undefined *)(iVar1 + 0x5a);
  puVar7[10] = *(undefined *)(iVar1 + 0x5b);
  puVar7[0xb] = (char)((uint)*(undefined4 *)(iVar6 + 0x134) >> 8);
  puVar7[0xc] = (char)*(undefined4 *)(iVar6 + 0x134);
  iVar1 = param_1[0x16];
  *(undefined4 *)(iVar6 + 0x130) = param_2;
  *(int *)(iVar6 + 0x134) = *(int *)(iVar6 + 0x134) + 0xd;
  ssl3_record_sequence_update(iVar1 + 0x54);
  if (param_5 == 0) {
    iVar1 = param_1[0x16];
    *(undefined4 *)(iVar6 + 0x104) = 0;
    *(undefined4 *)(iVar6 + 0x108) = *(undefined4 *)(iVar6 + 0x134);
    *(int *)(iVar1 + 0x168) = param_4;
    *(undefined4 *)(iVar1 + 0x174) = param_3;
    *(undefined4 *)(iVar1 + 0x16c) = param_2;
    *(int *)(iVar1 + 0x170) = param_4;
    iVar6 = ssl3_write_pending(param_1,param_2,param_3,param_4);
    return iVar6;
  }
  return *(int *)(iVar6 + 0x134);
}

