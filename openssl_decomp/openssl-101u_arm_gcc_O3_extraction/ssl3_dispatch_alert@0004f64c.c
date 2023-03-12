
int ssl3_dispatch_alert(int *param_1)

{
  EVP_MD *pEVar1;
  COMP_CTX *ctx;
  ulong uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined uVar6;
  uint uVar7;
  code *pcVar8;
  int iVar9;
  int iVar10;
  undefined2 *puVar11;
  undefined *puVar12;
  undefined *unaff_r10;
  int local_30;
  int local_2c;
  
  iVar10 = param_1[0x16];
  puVar11 = (undefined2 *)(iVar10 + 400);
  *(undefined4 *)(iVar10 + 0x18c) = 0;
  if (*(int *)(iVar10 + 0x108) == 0) {
    iVar3 = iVar10;
    if (*(int *)(iVar10 + 0xfc) == 0) {
      iVar3 = ssl3_setup_write_buffer();
      if (iVar3 != 0) {
        iVar3 = param_1[0x16];
        goto LAB_0004f676;
      }
    }
    else {
LAB_0004f676:
      if (param_1[0x30] == 0) {
LAB_0004f84e:
        if (param_1[0x23] != 0) {
          local_30 = 0;
          goto LAB_0004f6a8;
        }
LAB_0004f6b8:
        local_30 = 0;
      }
      else {
        if (param_1[0x23] == 0) goto LAB_0004f6b8;
        pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
        if (pEVar1 == (EVP_MD *)0x0) goto LAB_0004f84e;
        pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
        local_30 = EVP_MD_size(pEVar1);
        if (local_30 < 0) goto LAB_0004f904;
LAB_0004f6a8:
        if (*(int *)(param_1[0x16] + 0xe4) == 0) {
          *(undefined4 *)(param_1[0x16] + 0xe4) = 1;
        }
      }
      iVar5 = *(int *)(iVar10 + 0xfc);
      uVar7 = 3U - iVar5 & 7;
      *(uint *)(iVar10 + 0x104) = uVar7;
      iVar4 = iVar5 + uVar7;
      *(undefined *)(iVar5 + uVar7) = 0x15;
      iVar5 = *param_1;
      *(undefined4 *)(iVar3 + 0x130) = 0x15;
      *(char *)(iVar4 + 1) = (char)((uint)iVar5 >> 8);
      if ((param_1[0xd] == 0x1111) && (param_1[100] == 0)) {
        iVar9 = *param_1;
        iVar5 = iVar9;
        if (iVar9 >> 8 != 3) goto LAB_0004f6ea;
        if (0x301 < iVar9) {
          unaff_r10 = (undefined *)(iVar4 + 3);
          iVar5 = 1;
        }
        uVar6 = (undefined)iVar5;
        if (iVar9 < 0x302) goto LAB_0004f6ea;
      }
      else {
        iVar5 = *param_1;
LAB_0004f6ea:
        uVar6 = (undefined)iVar5;
        unaff_r10 = (undefined *)(iVar4 + 3);
      }
      *(undefined *)(iVar4 + 2) = uVar6;
      puVar12 = unaff_r10 + 2;
      if (((EVP_CIPHER_CTX *)param_1[0x23] == (EVP_CIPHER_CTX *)0x0) || (*param_1 < 0x302)) {
LAB_0004f708:
        local_2c = 0;
      }
      else {
        uVar2 = EVP_CIPHER_CTX_flags((EVP_CIPHER_CTX *)param_1[0x23]);
        if ((uVar2 & 0xf0007) == 2) {
          local_2c = EVP_CIPHER_CTX_iv_length((EVP_CIPHER_CTX *)param_1[0x23]);
          if (local_2c < 2) goto LAB_0004f708;
        }
        else {
          if ((uVar2 & 0xf0007) != 6) goto LAB_0004f708;
          local_2c = 8;
        }
      }
      ctx = (COMP_CTX *)param_1[0x25];
      *(undefined2 **)(iVar3 + 0x140) = puVar11;
      *(undefined **)(iVar3 + 0x13c) = puVar12 + local_2c;
      *(undefined4 *)(iVar3 + 0x134) = 2;
      if (ctx == (COMP_CTX *)0x0) {
        *(undefined2 *)(puVar12 + local_2c) = *puVar11;
        *(undefined4 *)(iVar3 + 0x140) = *(undefined4 *)(iVar3 + 0x13c);
      }
      else {
        iVar5 = param_1[0x16];
        iVar4 = COMP_compress_block(ctx,*(uchar **)(iVar5 + 0x13c),0x4400,*(uchar **)(iVar5 + 0x140)
                                    ,*(int *)(iVar5 + 0x134));
        if (iVar4 < 0) {
          ERR_put_error(0x14,0x68,0x8d,"s3_pkt.c",0x348);
          goto LAB_0004f904;
        }
        *(int *)(iVar5 + 0x134) = iVar4;
        *(undefined4 *)(iVar5 + 0x140) = *(undefined4 *)(iVar5 + 0x13c);
      }
      if (local_30 != 0) {
        iVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 4))
                          (param_1,puVar12 + local_2c + *(int *)(iVar3 + 0x134),1);
        if (iVar4 < 0) goto LAB_0004f904;
        *(int *)(iVar3 + 0x134) = *(int *)(iVar3 + 0x134) + local_30;
      }
      *(undefined **)(iVar3 + 0x140) = puVar12;
      *(undefined **)(iVar3 + 0x13c) = puVar12;
      if (local_2c != 0) {
        *(int *)(iVar3 + 0x134) = *(int *)(iVar3 + 0x134) + local_2c;
      }
      iVar4 = (***(code ***)(param_1[2] + 100))(param_1,1);
      if (0 < iVar4) {
        *unaff_r10 = (char)((uint)*(undefined4 *)(iVar3 + 0x134) >> 8);
        unaff_r10[1] = (char)*(undefined4 *)(iVar3 + 0x134);
        iVar5 = param_1[0x16];
        *(undefined4 *)(iVar3 + 0x130) = 0x15;
        iVar4 = *(int *)(iVar3 + 0x134) + 5;
        *(int *)(iVar3 + 0x134) = iVar4;
        *(int *)(iVar10 + 0x108) = iVar4;
        *(undefined2 **)(iVar5 + 0x174) = puVar11;
        *(undefined4 *)(iVar5 + 0x16c) = 0x15;
        *(undefined4 *)(iVar5 + 0x168) = 2;
        *(undefined4 *)(iVar5 + 0x170) = 2;
        iVar10 = ssl3_write_pending(param_1,0x15,puVar11,2);
        goto joined_r0x0004f83c;
      }
    }
LAB_0004f904:
    iVar10 = -1;
  }
  else {
    iVar10 = ssl3_write_pending(param_1,0x15,puVar11,2);
joined_r0x0004f83c:
    if (0 < iVar10) {
      if (*(char *)(param_1[0x16] + 400) == '\x02') {
        BIO_ctrl((BIO *)param_1[4],0xb,0,(void *)0x0);
      }
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])(1,*param_1,0x15,param_1[0x16] + 400,2,param_1,param_1[0x1a]);
      }
      pcVar8 = (code *)param_1[0x34];
      if ((pcVar8 != (code *)0x0) ||
         (pcVar8 = *(code **)(param_1[0x39] + 0x9c), pcVar8 != (code *)0x0)) {
        (*pcVar8)(param_1,0x4008,
                  CONCAT11(*(undefined *)(param_1[0x16] + 400),*(undefined *)(param_1[0x16] + 0x191)
                          ));
      }
      return iVar10;
    }
  }
  *(undefined4 *)(param_1[0x16] + 0x18c) = 1;
  return iVar10;
}

