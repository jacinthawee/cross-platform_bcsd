
int ssl3_dispatch_alert(int *param_1)

{
  EVP_MD *pEVar1;
  COMP_CTX *ctx;
  ulong uVar2;
  int iVar3;
  int iVar4;
  undefined uVar5;
  uint uVar6;
  code *pcVar7;
  int iVar8;
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
  if ((*(int *)(iVar10 + 0xfc) == 0) && (iVar9 = ssl3_setup_write_buffer(), iVar9 == 0)) {
LAB_0005236e:
    iVar9 = -1;
  }
  else {
    if (*(int *)(iVar10 + 0x108) == 0) {
      iVar9 = param_1[0x16];
      if (*(int *)(iVar9 + 0x18c) == 0) {
        if (param_1[0x30] == 0) goto LAB_00052274;
LAB_000520ae:
        if (param_1[0x23] == 0) goto LAB_000520e6;
        pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
        if (pEVar1 == (EVP_MD *)0x0) goto LAB_00052274;
        pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
        local_30 = EVP_MD_size(pEVar1);
        if (local_30 < 0) goto LAB_0005236e;
LAB_000520d6:
        if (*(int *)(param_1[0x16] + 0xe4) == 0) {
          *(undefined4 *)(param_1[0x16] + 0xe4) = 1;
        }
      }
      else {
        iVar9 = (**(code **)(param_1[2] + 0x3c))(param_1);
        if (iVar9 < 1) goto LAB_00052296;
        iVar9 = param_1[0x16];
        if (param_1[0x30] != 0) goto LAB_000520ae;
LAB_00052274:
        if (param_1[0x23] != 0) {
          local_30 = 0;
          goto LAB_000520d6;
        }
LAB_000520e6:
        local_30 = 0;
      }
      iVar4 = *(int *)(iVar10 + 0xfc);
      uVar6 = 3U - iVar4 & 7;
      *(uint *)(iVar10 + 0x104) = uVar6;
      iVar3 = iVar4 + uVar6;
      *(undefined *)(iVar4 + uVar6) = 0x15;
      iVar4 = *param_1;
      *(undefined4 *)(iVar9 + 0x130) = 0x15;
      *(char *)(iVar3 + 1) = (char)((uint)iVar4 >> 8);
      if ((param_1[0xd] == 0x1111) && (param_1[100] == 0)) {
        iVar8 = *param_1;
        iVar4 = iVar8;
        if (iVar8 >> 8 != 3) goto LAB_00052118;
        if (0x301 < iVar8) {
          unaff_r10 = (undefined *)(iVar3 + 3);
          iVar4 = 1;
        }
        uVar5 = (undefined)iVar4;
        if (iVar8 < 0x302) goto LAB_00052118;
      }
      else {
        iVar4 = *param_1;
LAB_00052118:
        uVar5 = (undefined)iVar4;
        unaff_r10 = (undefined *)(iVar3 + 3);
      }
      *(undefined *)(iVar3 + 2) = uVar5;
      puVar12 = unaff_r10 + 2;
      if (((EVP_CIPHER_CTX *)param_1[0x23] == (EVP_CIPHER_CTX *)0x0) || (*param_1 < 0x302)) {
LAB_00052136:
        local_2c = 0;
      }
      else {
        uVar2 = EVP_CIPHER_CTX_flags((EVP_CIPHER_CTX *)param_1[0x23]);
        if ((uVar2 & 0xf0007) == 2) {
          local_2c = EVP_CIPHER_CTX_iv_length((EVP_CIPHER_CTX *)param_1[0x23]);
          if (local_2c < 2) goto LAB_00052136;
        }
        else {
          if ((uVar2 & 0xf0007) != 6) goto LAB_00052136;
          local_2c = 8;
        }
      }
      ctx = (COMP_CTX *)param_1[0x25];
      *(undefined2 **)(iVar9 + 0x140) = puVar11;
      *(undefined **)(iVar9 + 0x13c) = puVar12 + local_2c;
      *(undefined4 *)(iVar9 + 0x134) = 2;
      if (ctx == (COMP_CTX *)0x0) {
        *(undefined2 *)(puVar12 + local_2c) = *puVar11;
        *(undefined4 *)(iVar9 + 0x140) = *(undefined4 *)(iVar9 + 0x13c);
      }
      else {
        iVar4 = param_1[0x16];
        iVar3 = COMP_compress_block(ctx,*(uchar **)(iVar4 + 0x13c),0x4400,*(uchar **)(iVar4 + 0x140)
                                    ,*(int *)(iVar4 + 0x134));
        if (iVar3 < 0) {
          iVar9 = -1;
          ERR_put_error(0x14,0x68,0x8d,"s3_pkt.c",0x318);
          goto LAB_00052296;
        }
        *(int *)(iVar4 + 0x134) = iVar3;
        *(undefined4 *)(iVar4 + 0x140) = *(undefined4 *)(iVar4 + 0x13c);
      }
      if (local_30 != 0) {
        iVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 4))
                          (param_1,puVar12 + local_2c + *(int *)(iVar9 + 0x134),1);
        if (iVar3 < 0) goto LAB_0005236e;
        *(int *)(iVar9 + 0x134) = *(int *)(iVar9 + 0x134) + local_30;
      }
      *(undefined **)(iVar9 + 0x140) = puVar12;
      *(undefined **)(iVar9 + 0x13c) = puVar12;
      if (local_2c != 0) {
        *(int *)(iVar9 + 0x134) = *(int *)(iVar9 + 0x134) + local_2c;
      }
      (***(code ***)(param_1[2] + 100))(param_1,1);
      *unaff_r10 = (char)((uint)*(undefined4 *)(iVar9 + 0x134) >> 8);
      unaff_r10[1] = (char)*(undefined4 *)(iVar9 + 0x134);
      iVar4 = param_1[0x16];
      *(undefined4 *)(iVar9 + 0x130) = 0x15;
      iVar3 = *(int *)(iVar9 + 0x134) + 5;
      *(int *)(iVar9 + 0x134) = iVar3;
      *(int *)(iVar10 + 0x108) = iVar3;
      *(undefined2 **)(iVar4 + 0x174) = puVar11;
      *(undefined4 *)(iVar4 + 0x16c) = 0x15;
      *(undefined4 *)(iVar4 + 0x168) = 2;
      *(undefined4 *)(iVar4 + 0x170) = 2;
      iVar9 = ssl3_write_pending(param_1,0x15,puVar11,2);
    }
    else {
      iVar9 = ssl3_write_pending(param_1,0x15,puVar11,2);
    }
    if (0 < iVar9) {
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
                  CONCAT11(*(undefined *)(param_1[0x16] + 400),*(undefined *)(param_1[0x16] + 0x191)
                          ));
      }
      return iVar9;
    }
  }
LAB_00052296:
  *(undefined4 *)(param_1[0x16] + 0x18c) = 1;
  return iVar9;
}

