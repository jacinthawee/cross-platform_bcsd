
int b64_puts(BIO *param_1,int param_2)

{
  bool bVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iStack_34;
  
  iVar5 = (*(code *)PTR_strlen_006a9a24)(param_2);
  piVar7 = (int *)param_1->ptr;
  (*(code *)PTR_BIO_clear_flags_006a8138)(param_1,0xf);
  puVar2 = PTR_EVP_EncodeInit_006a8af4;
  if (piVar7[4] != 1) {
    piVar7[4] = 1;
    *piVar7 = 0;
    piVar7[1] = 0;
    piVar7[2] = 0;
    (*(code *)puVar2)(piVar7 + 7);
  }
  if (0x5dd < piVar7[1]) {
    (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x17a,"ctx->buf_off < (int)sizeof(ctx->buf)");
  }
  iVar8 = *piVar7;
  if (0x5de < iVar8) {
    (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x17b,"ctx->buf_len <= (int)sizeof(ctx->buf)");
    iVar8 = *piVar7;
  }
  iVar6 = piVar7[1];
  if (iVar8 < iVar6) {
    (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x17c,"ctx->buf_len >= ctx->buf_off");
    iVar8 = *piVar7;
    iVar6 = piVar7[1];
  }
  iVar8 = iVar8 - iVar6;
  if (iVar8 < 1) {
LAB_0053fa6c:
    piVar7[1] = 0;
    *piVar7 = 0;
    if ((param_2 == 0) || (iVar5 < 1)) {
      return 0;
    }
    iStack_34 = 0;
    do {
      iVar8 = 0x400;
      if (iVar5 < 0x401) {
        iVar8 = iVar5;
      }
      uVar3 = (*(code *)PTR_BIO_test_flags_006a7868)(param_1,0xffffffff);
      if ((uVar3 & 0x100) == 0) {
        (*(code *)PTR_EVP_EncodeUpdate_006a8afc)(piVar7 + 7,piVar7 + 0x1f,piVar7,param_2,iVar8);
        iVar6 = *piVar7;
        if (0x5de < iVar6) {
          (*(code *)PTR_OpenSSLDie_006a7c5c)
                    ("bio_b64.c",0x1bf,"ctx->buf_len <= (int)sizeof(ctx->buf)");
          iVar6 = *piVar7;
        }
        if (iVar6 < piVar7[1]) {
          (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x1c0,"ctx->buf_len >= ctx->buf_off");
          iVar6 = *piVar7;
        }
        iStack_34 = iStack_34 + iVar8;
      }
      else {
        iVar6 = piVar7[2];
        if (iVar6 < 1) {
          if (iVar8 < 3) {
            (*(code *)PTR_memcpy_006a9aec)((int)piVar7 + 0x65a,param_2,iVar8);
            piVar7[2] = iVar8;
            return iVar8 + iStack_34;
          }
          iVar8 = (iVar8 / 3) * 3;
          iVar6 = (*(code *)PTR_EVP_EncodeBlock_006a8af8)(piVar7 + 0x1f,param_2,iVar8);
          *piVar7 = iVar6;
          if (0x5de < iVar6) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)
                      ("bio_b64.c",0x1b7,"ctx->buf_len <= (int)sizeof(ctx->buf)");
            iVar6 = *piVar7;
          }
          if (iVar6 < piVar7[1]) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x1b8,"ctx->buf_len >= ctx->buf_off");
            iVar6 = *piVar7;
          }
          iStack_34 = iStack_34 + iVar8;
        }
        else {
          if (3 < iVar6) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x196,"ctx->tmp_len <= 3");
            iVar6 = piVar7[2];
          }
          iVar8 = 3 - iVar6;
          if (iVar5 < 3 - iVar6) {
            iVar8 = iVar5;
          }
          (*(code *)PTR_memcpy_006a9aec)((int)piVar7 + iVar6 + 0x65a,param_2,iVar8);
          iVar6 = piVar7[2];
          iStack_34 = iStack_34 + iVar8;
          piVar7[2] = iVar8 + iVar6;
          if (iVar8 + iVar6 < 3) {
            return iStack_34;
          }
          iVar6 = (*(code *)PTR_EVP_EncodeBlock_006a8af8)(piVar7 + 0x1f,(int)piVar7 + 0x65a);
          *piVar7 = iVar6;
          if (0x5de < iVar6) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)
                      ("bio_b64.c",0x1a5,"ctx->buf_len <= (int)sizeof(ctx->buf)");
            iVar6 = *piVar7;
          }
          if (iVar6 < piVar7[1]) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x1a6,"ctx->buf_len >= ctx->buf_off");
            iVar6 = *piVar7;
          }
          piVar7[2] = 0;
        }
      }
      param_2 = param_2 + iVar8;
      piVar7[1] = 0;
      if (0 < iVar6) {
        iVar4 = (*(code *)PTR_BIO_write_006a6e14)(param_1->next_bio,piVar7 + 0x1f,iVar6);
        bVar1 = iVar6 < iVar4;
        while( true ) {
          if (iVar4 < 1) {
            BIO_copy_next_retry(param_1);
            if (iStack_34 != 0) {
              iVar4 = iStack_34;
            }
            return iVar4;
          }
          if (bVar1) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x1ce,"i <= n");
          }
          iVar6 = iVar6 - iVar4;
          iVar4 = iVar4 + piVar7[1];
          piVar7[1] = iVar4;
          if (0x5de < iVar4) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)
                      ("bio_b64.c",0x1d1,"ctx->buf_off <= (int)sizeof(ctx->buf)");
            iVar4 = piVar7[1];
          }
          if (*piVar7 < iVar4) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x1d2,"ctx->buf_len >= ctx->buf_off");
          }
          if (iVar6 < 1) break;
          iVar4 = (*(code *)PTR_BIO_write_006a6e14)
                            (param_1->next_bio,(int)piVar7 + piVar7[1] + 0x7c,iVar6);
          bVar1 = iVar6 < iVar4;
        }
      }
      iVar5 = iVar5 - iVar8;
      *piVar7 = 0;
      piVar7[1] = 0;
    } while (0 < iVar5);
  }
  else {
    while( true ) {
      iStack_34 = (*(code *)PTR_BIO_write_006a6e14)
                            (param_1->next_bio,(int)piVar7 + iVar6 + 0x7c,iVar8);
      bVar1 = iVar8 < iStack_34;
      if (iStack_34 < 1) break;
      iVar8 = iVar8 - iStack_34;
      if (bVar1) {
        (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x184,"i <= n");
      }
      iStack_34 = iStack_34 + piVar7[1];
      piVar7[1] = iStack_34;
      if (0x5de < iStack_34) {
        (*(code *)PTR_OpenSSLDie_006a7c5c)
                  ("bio_b64.c",0x186,"ctx->buf_off <= (int)sizeof(ctx->buf)");
        iStack_34 = piVar7[1];
      }
      if (*piVar7 < iStack_34) {
        (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x187,"ctx->buf_len >= ctx->buf_off");
      }
      if (iVar8 < 1) goto LAB_0053fa6c;
      iVar6 = piVar7[1];
    }
    BIO_copy_next_retry(param_1);
  }
  return iStack_34;
}

