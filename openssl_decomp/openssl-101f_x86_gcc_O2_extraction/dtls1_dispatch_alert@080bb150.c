
int dtls1_dispatch_alert(undefined4 *param_1)

{
  uchar *buf;
  undefined *puVar1;
  undefined4 uVar2;
  EVP_MD *pEVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  int in_GS_OFFSET;
  int local_38;
  int local_34;
  undefined2 local_22;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar6 = param_1[0x16];
  *(undefined4 *)(iVar6 + 0x18c) = 0;
  local_22 = CONCAT11(*(undefined *)(iVar6 + 0x191),*(undefined *)(iVar6 + 400));
  if (*(int *)(iVar6 + 0x108) == 0) {
    if (((param_1[0x30] == 0) || (param_1[0x23] == 0)) ||
       (pEVar3 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]), pEVar3 == (EVP_MD *)0x0)) {
      local_38 = 0;
LAB_080bb1f6:
      puVar1 = *(undefined **)(iVar6 + 0xfc);
      *puVar1 = 0x15;
      uVar2 = *param_1;
      buf = puVar1 + 0xd;
      *(undefined4 *)(iVar6 + 0x130) = 0x15;
      puVar1[1] = (char)((uint)uVar2 >> 8);
      puVar1[2] = (char)*param_1;
      if (((EVP_CIPHER **)param_1[0x23] == (EVP_CIPHER **)0x0) ||
         (uVar4 = EVP_CIPHER_flags(*(EVP_CIPHER **)param_1[0x23]), (uVar4 & 2) == 0)) {
        local_34 = 0;
      }
      else {
        local_34 = EVP_CIPHER_block_size(*(EVP_CIPHER **)param_1[0x23]);
      }
      iVar5 = param_1[0x25];
      *(undefined4 *)(iVar6 + 0x134) = 2;
      *(undefined2 **)(iVar6 + 0x140) = &local_22;
      *(uchar **)(iVar6 + 0x13c) = buf + local_34;
      if (iVar5 == 0) {
        *(undefined2 *)(buf + local_34) = local_22;
        *(undefined4 *)(iVar6 + 0x140) = *(undefined4 *)(iVar6 + 0x13c);
      }
      else {
        iVar5 = ssl3_do_compress(param_1);
        if (iVar5 == 0) {
          ERR_put_error(0x14,0xf5,0x8d,"d1_pkt.c",0x632);
          goto LAB_080bb445;
        }
      }
      if (local_38 != 0) {
        iVar5 = (**(code **)(*(int *)(param_1[2] + 100) + 4))
                          (param_1,buf + local_34 + *(int *)(iVar6 + 0x134),1);
        if (iVar5 < 0) goto LAB_080bb445;
        *(int *)(iVar6 + 0x134) = *(int *)(iVar6 + 0x134) + local_38;
      }
      *(uchar **)(iVar6 + 0x140) = buf;
      *(uchar **)(iVar6 + 0x13c) = buf;
      if (local_34 != 0) {
        RAND_pseudo_bytes(buf,local_34);
        *(int *)(iVar6 + 0x134) = *(int *)(iVar6 + 0x134) + local_34;
      }
      (***(code ***)(param_1[2] + 100))(param_1,1);
      puVar1[3] = *(undefined *)(param_1[0x17] + 0x20b);
      puVar1[4] = (char)*(undefined2 *)(param_1[0x17] + 0x20a);
      iVar5 = param_1[0x16];
      *(undefined4 *)(puVar1 + 5) = *(undefined4 *)(iVar5 + 0x56);
      *(undefined2 *)(puVar1 + 9) = *(undefined2 *)(iVar5 + 0x5a);
      puVar1[0xb] = (char)((uint)*(undefined4 *)(iVar6 + 0x134) >> 8);
      puVar1[0xc] = (char)*(undefined4 *)(iVar6 + 0x134);
      iVar5 = param_1[0x16];
      *(int *)(iVar6 + 0x134) = *(int *)(iVar6 + 0x134) + 0xd;
      *(undefined4 *)(iVar6 + 0x130) = 0x15;
      ssl3_record_sequence_update(iVar5 + 0x54);
      *(undefined4 *)(iVar6 + 0x104) = 0;
      *(undefined4 *)(iVar6 + 0x108) = *(undefined4 *)(iVar6 + 0x134);
      iVar6 = param_1[0x16];
      *(undefined4 *)(iVar6 + 0x168) = 2;
      *(undefined2 **)(iVar6 + 0x174) = &local_22;
      *(undefined4 *)(iVar6 + 0x16c) = 0x15;
      *(undefined4 *)(iVar6 + 0x170) = 2;
      goto LAB_080bb360;
    }
    pEVar3 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
    local_38 = EVP_MD_size(pEVar3);
    if (-1 < local_38) goto LAB_080bb1f6;
LAB_080bb445:
    iVar6 = -1;
  }
  else {
    OpenSSLDie("d1_pkt.c",0x5cc,"0");
LAB_080bb360:
    iVar6 = ssl3_write_pending(param_1,0x15,&local_22,2);
    if (0 < iVar6) {
      if (*(char *)(param_1[0x16] + 400) == '\x02') {
        BIO_ctrl((BIO *)param_1[4],0xb,0,(void *)0x0);
      }
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])(1,*param_1,0x15,param_1[0x16] + 400,2,param_1,param_1[0x1a]);
      }
      pcVar7 = (code *)param_1[0x34];
      if ((pcVar7 != (code *)0x0) ||
         (pcVar7 = *(code **)(param_1[0x39] + 0x9c), pcVar7 != (code *)0x0)) {
        (*pcVar7)(param_1,0x4008,
                  *(ushort *)(param_1[0x16] + 400) << 8 | *(ushort *)(param_1[0x16] + 400) >> 8);
      }
      goto LAB_080bb3da;
    }
  }
  *(undefined4 *)(param_1[0x16] + 0x18c) = 1;
LAB_080bb3da:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}

