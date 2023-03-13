
undefined4 ciphers_main(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  BIO *bio;
  int iVar6;
  SSL_CTX *ctx;
  SSL *s;
  char *pcVar7;
  _STACK *p_Var8;
  int iVar9;
  SSL_CIPHER *c;
  ulong uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined1 *puVar14;
  undefined4 uVar15;
  byte *pbVar16;
  byte *pbVar17;
  int in_GS_OFFSET;
  bool bVar18;
  bool bVar19;
  byte bVar20;
  SSL_METHOD *local_23c;
  byte *local_234;
  char local_220 [512];
  int local_20;
  
  bVar20 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_23c = SSLv23_server_method();
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  bio = BIO_new_fp(stdout,0);
  iVar6 = load_config(bio_err,0);
  if (iVar6 == 0) {
LAB_08080b10:
    uVar15 = 1;
  }
  else {
    if (param_1 < 2) {
      SSL_library_init();
      ctx = SSL_CTX_new(local_23c);
      if (ctx == (SSL_CTX *)0x0) goto LAB_08080af3;
      s = SSL_new(ctx);
      if (s != (SSL *)0x0) {
LAB_08080a9a:
        iVar6 = 0;
        while (pcVar7 = SSL_get_cipher_list(s,iVar6), pcVar7 != (char *)0x0) {
          if (iVar6 != 0) {
            BIO_printf(bio,":");
          }
          iVar6 = iVar6 + 1;
          BIO_printf(bio,"%s",pcVar7);
        }
        BIO_printf(bio,"\n");
LAB_08080bfa:
        uVar15 = 0;
        SSL_CTX_free(ctx);
        SSL_free(s);
        goto LAB_08080b15;
      }
    }
    else {
      iVar6 = 0;
      local_234 = (byte *)0x0;
      bVar5 = false;
      bVar4 = false;
      do {
        while( true ) {
          pbVar3 = *(byte **)(param_2 + 4 + iVar6 * 4);
          bVar1 = *pbVar3;
          bVar18 = 0x2d < bVar1;
          bVar19 = bVar1 == 0x2d;
          if (bVar19) break;
LAB_08080990:
          iVar9 = 6;
          pbVar16 = pbVar3;
          pbVar17 = (byte *)"-ssl3";
          do {
            if (iVar9 == 0) break;
            iVar9 = iVar9 + -1;
            bVar18 = *pbVar16 < *pbVar17;
            bVar19 = *pbVar16 == *pbVar17;
            pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
            pbVar17 = pbVar17 + (uint)bVar20 * -2 + 1;
          } while (bVar19);
          bVar18 = (!bVar18 && !bVar19) == bVar18;
          if (!bVar18) {
            iVar9 = 6;
            pbVar16 = pbVar3;
            pbVar17 = (byte *)"-tls1";
            do {
              if (iVar9 == 0) break;
              iVar9 = iVar9 + -1;
              bVar18 = *pbVar16 == *pbVar17;
              pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
              pbVar17 = pbVar17 + (uint)bVar20 * -2 + 1;
            } while (bVar18);
            if (bVar18) {
              local_23c = TLSv1_client_method();
              goto LAB_080809f4;
            }
            iVar9 = 2;
            pbVar16 = pbVar3;
            pbVar17 = &DAT_081f9673;
            do {
              if (iVar9 == 0) break;
              iVar9 = iVar9 + -1;
              bVar18 = *pbVar16 == *pbVar17;
              pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
              pbVar17 = pbVar17 + (uint)bVar20 * -2 + 1;
            } while (bVar18);
            if ((!bVar18) &&
               (((local_234 = pbVar3, bVar1 != 0x2d || (pbVar3[1] != 0x3f)) || (pbVar3[2] != 0))))
            goto LAB_080809f4;
            puVar14 = ciphers_usage;
            iVar6 = ciphers_usage._0_4_;
            while (iVar6 != 0) {
              puVar14 = (undefined1 *)((int)puVar14 + 4);
              BIO_printf(bio_err,"%s",iVar6);
              iVar6 = *(int *)puVar14;
            }
            goto LAB_08080b10;
          }
          local_23c = SSLv3_client_method();
LAB_080809f4:
          iVar6 = iVar6 + 1;
          if (param_1 + -1 == iVar6) goto LAB_08080a3d;
        }
        bVar2 = pbVar3[1];
        if (bVar2 != 0x76) {
          bVar18 = bVar2 < 0x56;
          bVar19 = bVar2 == 0x56;
          if (bVar19) {
            bVar18 = false;
            bVar19 = pbVar3[2] == 0;
            if (bVar19) {
              bVar5 = true;
              goto LAB_08080a2c;
            }
          }
          goto LAB_08080990;
        }
        bVar18 = false;
        bVar19 = pbVar3[2] == 0;
        if (!bVar19) goto LAB_08080990;
LAB_08080a2c:
        iVar6 = iVar6 + 1;
        bVar4 = true;
      } while (param_1 + -1 != iVar6);
LAB_08080a3d:
      SSL_library_init();
      ctx = SSL_CTX_new(local_23c);
      if (ctx == (SSL_CTX *)0x0) {
LAB_08080af3:
        SSL_load_error_strings();
        ERR_print_errors(bio_err);
        goto LAB_08080b10;
      }
      if ((local_234 == (byte *)0x0) ||
         (iVar6 = SSL_CTX_set_cipher_list(ctx,(char *)local_234), iVar6 != 0)) {
        s = SSL_new(ctx);
        if (s != (SSL *)0x0) {
          if (!bVar4) goto LAB_08080a9a;
          p_Var8 = (_STACK *)SSL_get_ciphers(s);
          for (iVar6 = 0; iVar9 = sk_num(p_Var8), iVar6 < iVar9; iVar6 = iVar6 + 1) {
            c = (SSL_CIPHER *)sk_value(p_Var8,iVar6);
            if (bVar5) {
              uVar10 = SSL_CIPHER_get_id(c);
              uVar11 = uVar10 >> 8 & 0xff;
              uVar12 = uVar10 >> 0x10 & 0xff;
              uVar13 = uVar10 & 0xff;
              if ((uVar10 & 0xff000000) == 0x2000000) {
                BIO_printf(bio,"     0x%02X,0x%02X,0x%02X - ",uVar12,uVar11,uVar13);
              }
              else if ((uVar10 & 0xff000000) == 0x3000000) {
                BIO_printf(bio,"          0x%02X,0x%02X - ",uVar11,uVar13);
              }
              else {
                BIO_printf(bio,"0x%02X,0x%02X,0x%02X,0x%02X - ",uVar10 >> 0x18,uVar12,uVar11,uVar13)
                ;
              }
            }
            pcVar7 = SSL_CIPHER_description(c,local_220,0x200);
            BIO_puts(bio,pcVar7);
          }
          goto LAB_08080bfa;
        }
      }
      else {
        BIO_printf(bio_err,"Error in cipher list\n");
      }
    }
    SSL_load_error_strings();
    uVar15 = 1;
    ERR_print_errors(bio_err);
    SSL_CTX_free(ctx);
  }
LAB_08080b15:
  if (bio != (BIO *)0x0) {
    BIO_free_all(bio);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar15;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

