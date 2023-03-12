
int b64_write(BIO *param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int local_34;
  
  piVar6 = (int *)param_1->ptr;
  (*(code *)PTR_BIO_clear_flags_006a8138)(param_1,0xf);
  puVar2 = PTR_EVP_EncodeInit_006a8af4;
  if (piVar6[4] != 1) {
    piVar6[4] = 1;
    *piVar6 = 0;
    piVar6[1] = 0;
    piVar6[2] = 0;
    (*(code *)puVar2)(piVar6 + 7);
  }
  if (0x5dd < piVar6[1]) {
    (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x17a,"ctx->buf_off < (int)sizeof(ctx->buf)");
  }
  iVar7 = *piVar6;
  if (0x5de < iVar7) {
    (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x17b,"ctx->buf_len <= (int)sizeof(ctx->buf)");
    iVar7 = *piVar6;
  }
  iVar5 = piVar6[1];
  if (iVar7 < iVar5) {
    (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x17c,"ctx->buf_len >= ctx->buf_off");
    iVar7 = *piVar6;
    iVar5 = piVar6[1];
  }
  iVar7 = iVar7 - iVar5;
  if (iVar7 < 1) {
LAB_0053fa6c:
    piVar6[1] = 0;
    *piVar6 = 0;
    if ((param_2 == 0) || (param_3 < 1)) {
      return 0;
    }
    local_34 = 0;
    do {
      iVar7 = 0x400;
      if (param_3 < 0x401) {
        iVar7 = param_3;
      }
      uVar3 = (*(code *)PTR_BIO_test_flags_006a7868)(param_1,0xffffffff);
      if ((uVar3 & 0x100) == 0) {
        (*(code *)PTR_EVP_EncodeUpdate_006a8afc)(piVar6 + 7,piVar6 + 0x1f,piVar6,param_2,iVar7);
        iVar5 = *piVar6;
        if (0x5de < iVar5) {
          (*(code *)PTR_OpenSSLDie_006a7c5c)
                    ("bio_b64.c",0x1bf,"ctx->buf_len <= (int)sizeof(ctx->buf)");
          iVar5 = *piVar6;
        }
        if (iVar5 < piVar6[1]) {
          (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x1c0,"ctx->buf_len >= ctx->buf_off");
          iVar5 = *piVar6;
        }
        local_34 = local_34 + iVar7;
      }
      else {
        iVar5 = piVar6[2];
        if (iVar5 < 1) {
          if (iVar7 < 3) {
            (*(code *)PTR_memcpy_006a9aec)((int)piVar6 + 0x65a,param_2,iVar7);
            piVar6[2] = iVar7;
            return iVar7 + local_34;
          }
          iVar7 = (iVar7 / 3) * 3;
          iVar5 = (*(code *)PTR_EVP_EncodeBlock_006a8af8)(piVar6 + 0x1f,param_2,iVar7);
          *piVar6 = iVar5;
          if (0x5de < iVar5) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)
                      ("bio_b64.c",0x1b7,"ctx->buf_len <= (int)sizeof(ctx->buf)");
            iVar5 = *piVar6;
          }
          if (iVar5 < piVar6[1]) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x1b8,"ctx->buf_len >= ctx->buf_off");
            iVar5 = *piVar6;
          }
          local_34 = local_34 + iVar7;
        }
        else {
          if (3 < iVar5) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x196,"ctx->tmp_len <= 3");
            iVar5 = piVar6[2];
          }
          iVar7 = 3 - iVar5;
          if (param_3 < 3 - iVar5) {
            iVar7 = param_3;
          }
          (*(code *)PTR_memcpy_006a9aec)((int)piVar6 + iVar5 + 0x65a,param_2,iVar7);
          iVar5 = piVar6[2];
          local_34 = local_34 + iVar7;
          piVar6[2] = iVar7 + iVar5;
          if (iVar7 + iVar5 < 3) {
            return local_34;
          }
          iVar5 = (*(code *)PTR_EVP_EncodeBlock_006a8af8)(piVar6 + 0x1f,(int)piVar6 + 0x65a);
          *piVar6 = iVar5;
          if (0x5de < iVar5) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)
                      ("bio_b64.c",0x1a5,"ctx->buf_len <= (int)sizeof(ctx->buf)");
            iVar5 = *piVar6;
          }
          if (iVar5 < piVar6[1]) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x1a6,"ctx->buf_len >= ctx->buf_off");
            iVar5 = *piVar6;
          }
          piVar6[2] = 0;
        }
      }
      param_2 = param_2 + iVar7;
      piVar6[1] = 0;
      if (0 < iVar5) {
        iVar4 = (*(code *)PTR_BIO_write_006a6e14)(param_1->next_bio,piVar6 + 0x1f,iVar5);
        bVar1 = iVar5 < iVar4;
        while( true ) {
          if (iVar4 < 1) {
            BIO_copy_next_retry(param_1);
            if (local_34 != 0) {
              iVar4 = local_34;
            }
            return iVar4;
          }
          if (bVar1) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x1ce,"i <= n");
          }
          iVar5 = iVar5 - iVar4;
          iVar4 = iVar4 + piVar6[1];
          piVar6[1] = iVar4;
          if (0x5de < iVar4) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)
                      ("bio_b64.c",0x1d1,"ctx->buf_off <= (int)sizeof(ctx->buf)");
            iVar4 = piVar6[1];
          }
          if (*piVar6 < iVar4) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x1d2,"ctx->buf_len >= ctx->buf_off");
          }
          if (iVar5 < 1) break;
          iVar4 = (*(code *)PTR_BIO_write_006a6e14)
                            (param_1->next_bio,(int)piVar6 + piVar6[1] + 0x7c,iVar5);
          bVar1 = iVar5 < iVar4;
        }
      }
      param_3 = param_3 - iVar7;
      *piVar6 = 0;
      piVar6[1] = 0;
    } while (0 < param_3);
  }
  else {
    while( true ) {
      local_34 = (*(code *)PTR_BIO_write_006a6e14)
                           (param_1->next_bio,(int)piVar6 + iVar5 + 0x7c,iVar7);
      bVar1 = iVar7 < local_34;
      if (local_34 < 1) break;
      iVar7 = iVar7 - local_34;
      if (bVar1) {
        (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x184,"i <= n");
      }
      local_34 = local_34 + piVar6[1];
      piVar6[1] = local_34;
      if (0x5de < local_34) {
        (*(code *)PTR_OpenSSLDie_006a7c5c)
                  ("bio_b64.c",0x186,"ctx->buf_off <= (int)sizeof(ctx->buf)");
        local_34 = piVar6[1];
      }
      if (*piVar6 < local_34) {
        (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_b64.c",0x187,"ctx->buf_len >= ctx->buf_off");
      }
      if (iVar7 < 1) goto LAB_0053fa6c;
      iVar5 = piVar6[1];
    }
    BIO_copy_next_retry(param_1);
  }
  return local_34;
}

