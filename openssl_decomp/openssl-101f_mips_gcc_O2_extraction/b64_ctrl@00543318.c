
int b64_ctrl(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined *UNRECOVERED_JUMPTABLE;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  
  UNRECOVERED_JUMPTABLE = PTR_BIO_ctrl_006a7f18;
  piVar6 = *(int **)(param_1 + 0x20);
  if (param_2 == 0xb) {
    iVar2 = *piVar6;
    iVar4 = piVar6[1];
LAB_00543590:
    do {
      if (iVar2 != iVar4) {
        do {
          piVar7 = *(int **)(param_1 + 0x20);
          (*(code *)PTR_BIO_clear_flags_006a9260)(param_1,0xf);
          UNRECOVERED_JUMPTABLE = PTR_EVP_EncodeInit_006a9c10;
          if (piVar7[4] != 1) {
            piVar7[4] = 1;
            *piVar7 = 0;
            piVar7[1] = 0;
            piVar7[2] = 0;
            (*(code *)UNRECOVERED_JUMPTABLE)(piVar7 + 7);
          }
          if (0x5dd < piVar7[1]) {
            (*(code *)PTR_OpenSSLDie_006a8d4c)
                      ("bio_b64.c",0x188,"ctx->buf_off < (int)sizeof(ctx->buf)");
          }
          iVar2 = *piVar7;
          if (0x5de < iVar2) {
            (*(code *)PTR_OpenSSLDie_006a8d4c)
                      ("bio_b64.c",0x189,"ctx->buf_len <= (int)sizeof(ctx->buf)");
            iVar2 = *piVar7;
          }
          iVar4 = piVar7[1];
          if (iVar2 < iVar4) {
            (*(code *)PTR_OpenSSLDie_006a8d4c)("bio_b64.c",0x18a,"ctx->buf_len >= ctx->buf_off");
            iVar2 = *piVar7;
            iVar4 = piVar7[1];
          }
          iVar2 = iVar2 - iVar4;
          if (0 < iVar2) {
            while( true ) {
              iVar4 = (*(code *)PTR_BIO_write_006a7f14)
                                (*(undefined4 *)(param_1 + 0x24),(int)piVar7 + iVar4 + 0x7c,iVar2);
              bVar1 = iVar2 < iVar4;
              if (iVar4 < 1) {
                (*(code *)PTR_BIO_copy_next_retry_006a9554)(param_1);
                if (iVar4 != 0) {
                  return iVar4;
                }
                iVar2 = *piVar6;
                iVar4 = piVar6[1];
                goto LAB_00543590;
              }
              iVar2 = iVar2 - iVar4;
              if (bVar1) {
                (*(code *)PTR_OpenSSLDie_006a8d4c)("bio_b64.c",0x194,"i <= n");
              }
              iVar4 = iVar4 + piVar7[1];
              piVar7[1] = iVar4;
              if (0x5de < iVar4) {
                (*(code *)PTR_OpenSSLDie_006a8d4c)
                          ("bio_b64.c",0x196,"ctx->buf_off <= (int)sizeof(ctx->buf)");
                iVar4 = piVar7[1];
              }
              if (*piVar7 < iVar4) {
                (*(code *)PTR_OpenSSLDie_006a8d4c)("bio_b64.c",0x197,"ctx->buf_len >= ctx->buf_off")
                ;
              }
              if (iVar2 < 1) break;
              iVar4 = piVar7[1];
            }
          }
          piVar7[1] = 0;
          *piVar7 = 0;
        } while (*piVar6 != piVar6[1]);
      }
      uVar3 = (*(code *)PTR_BIO_test_flags_006a8954)(param_1,0xffffffff);
      UNRECOVERED_JUMPTABLE = PTR_EVP_EncodeFinal_006a9c1c;
      if ((uVar3 & 0x100) == 0) {
        if ((piVar6[4] == 0) || (piVar6[7] == 0)) {
LAB_00543810:
          uVar5 = *(undefined4 *)(param_1 + 0x24);
          param_2 = 0xb;
          goto LAB_00543428;
        }
        piVar6[1] = 0;
        (*(code *)UNRECOVERED_JUMPTABLE)(piVar6 + 7,piVar6 + 0x1f,piVar6);
        iVar2 = *piVar6;
        iVar4 = piVar6[1];
        goto LAB_00543590;
      }
      if (piVar6[2] == 0) goto LAB_00543810;
      iVar2 = (*(code *)PTR_EVP_EncodeBlock_006a9c14)(piVar6 + 0x1f,(int)piVar6 + 0x65a);
      iVar4 = 0;
      piVar6[1] = 0;
      piVar6[2] = 0;
      *piVar6 = iVar2;
    } while( true );
  }
  if (param_2 < 0xc) {
    if (param_2 == 2) {
      if (piVar6[6] < 1) {
        return 1;
      }
      uVar5 = *(undefined4 *)(param_1 + 0x24);
      goto LAB_00543428;
    }
    if (param_2 == 10) {
      iVar2 = *piVar6;
      iVar4 = piVar6[1];
      if (iVar2 < iVar4) {
        (*(code *)PTR_OpenSSLDie_006a8d4c)("bio_b64.c",0x20b,"ctx->buf_len >= ctx->buf_off");
        iVar2 = *piVar6;
        iVar4 = piVar6[1];
      }
      if (0 < iVar2 - iVar4) {
        return iVar2 - iVar4;
      }
      uVar5 = *(undefined4 *)(param_1 + 0x24);
      param_2 = 10;
      goto LAB_00543428;
    }
    if (param_2 == 1) {
      uVar5 = *(undefined4 *)(param_1 + 0x24);
      piVar6[6] = 1;
      piVar6[5] = 1;
      piVar6[4] = 0;
                    /* WARNING: Could not recover jumptable at 0x005434f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (*(code *)UNRECOVERED_JUMPTABLE)(uVar5);
      return iVar2;
    }
  }
  else {
    if (param_2 == 0xd) {
      iVar2 = *piVar6;
      iVar4 = piVar6[1];
      if (iVar2 < iVar4) {
        (*(code *)PTR_OpenSSLDie_006a8d4c)("bio_b64.c",0x202,"ctx->buf_len >= ctx->buf_off");
        iVar2 = *piVar6;
        iVar4 = piVar6[1];
      }
      iVar2 = iVar2 - iVar4;
      if (iVar2 == 0) {
        if ((piVar6[4] != 0) && (piVar6[7] != 0)) {
          return 1;
        }
        uVar5 = *(undefined4 *)(param_1 + 0x24);
      }
      else {
        if (0 < iVar2) {
          return iVar2;
        }
        uVar5 = *(undefined4 *)(param_1 + 0x24);
      }
      param_2 = 0xd;
      goto LAB_00543428;
    }
    if (param_2 < 0xd) {
      return 1;
    }
    if (param_2 == 0x65) {
      (*(code *)PTR_BIO_clear_flags_006a9260)(param_1,0xf);
      iVar2 = (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)(param_1 + 0x24),0x65,param_3,param_4)
      ;
      (*(code *)PTR_BIO_copy_next_retry_006a9554)(param_1);
      return iVar2;
    }
  }
  uVar5 = *(undefined4 *)(param_1 + 0x24);
LAB_00543428:
                    /* WARNING: Could not recover jumptable at 0x0054344c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(code *)PTR_BIO_ctrl_006a7f18)(uVar5,param_2,param_3,param_4);
  return iVar2;
}

