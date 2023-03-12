
void ciphers_main(int param_1,char **param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  BIO *bio;
  int iVar6;
  SSL_CTX *ctx;
  SSL *s;
  _STACK *p_Var7;
  int iVar8;
  SSL_CIPHER *c;
  ulong uVar9;
  undefined *puVar10;
  uint uVar11;
  char *pcVar12;
  undefined **ppuVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uVar16;
  char *local_238;
  SSL_METHOD *local_234;
  char acStack_22c [512];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  local_234 = SSLv23_server_method();
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  bio = BIO_new_fp(stdout,0);
  iVar6 = load_config(bio_err,0);
  if (iVar6 == 0) {
LAB_000373ac:
    uVar14 = 1;
  }
  else {
    param_1 = param_1 + -1;
    if (param_1 < 1) {
      SSL_library_init();
      ctx = SSL_CTX_new(local_234);
      if (ctx == (SSL_CTX *)0x0) goto LAB_000373a2;
      s = SSL_new(ctx);
      if (s != (SSL *)0x0) {
LAB_0003736a:
        iVar6 = 0;
        while (pcVar12 = SSL_get_cipher_list(s,iVar6), pcVar12 != (char *)0x0) {
          if (iVar6 != 0) {
            BIO_printf(bio,":");
          }
          iVar6 = iVar6 + 1;
          BIO_printf(bio,"%s",pcVar12);
        }
        BIO_printf(bio,"\n");
LAB_00037430:
        uVar14 = 0;
        SSL_CTX_free(ctx);
        SSL_free(s);
        goto LAB_000373ae;
      }
    }
    else {
      local_238 = (char *)0x0;
      bVar5 = false;
      bVar3 = false;
      do {
        while( true ) {
          bVar2 = bVar5;
          param_2 = param_2 + 1;
          pcVar12 = *param_2;
          cVar1 = *pcVar12;
          if (cVar1 == '-') break;
LAB_000372c0:
          iVar6 = strcmp(pcVar12,"-ssl3");
          if (iVar6 != 0) {
            iVar6 = strcmp(pcVar12,"-tls1");
            if (iVar6 == 0) {
              local_234 = TLSv1_client_method();
              goto LAB_0003730e;
            }
            iVar6 = strncmp(pcVar12,"-h",2);
            if ((iVar6 != 0) &&
               (((local_238 = pcVar12, cVar1 != '-' || (pcVar12[1] != '?')) || (pcVar12[2] != '\0'))
               )) goto LAB_0003730e;
            ppuVar13 = &ciphers_usage;
            puVar10 = ciphers_usage;
            while (puVar10 != (undefined *)0x0) {
              BIO_printf(bio_err,"%s");
              ppuVar13 = ppuVar13 + 1;
              puVar10 = *ppuVar13;
            }
            goto LAB_000373ac;
          }
          local_234 = SSLv3_client_method();
LAB_0003730e:
          param_1 = param_1 + -1;
          bVar5 = bVar2;
          bVar4 = bVar3;
          if (param_1 == 0) goto LAB_00037338;
        }
        if (pcVar12[1] == 'v') {
          if (pcVar12[2] != '\0') goto LAB_000372c0;
          bVar3 = true;
          goto LAB_0003730e;
        }
        if ((pcVar12[1] != 'V') || (pcVar12[2] != '\0')) goto LAB_000372c0;
        param_1 = param_1 + -1;
        bVar2 = true;
        bVar5 = true;
        bVar3 = bVar2;
        bVar4 = true;
      } while (param_1 != 0);
LAB_00037338:
      SSL_library_init();
      ctx = SSL_CTX_new(local_234);
      if (ctx == (SSL_CTX *)0x0) {
LAB_000373a2:
        SSL_load_error_strings();
        ERR_print_errors(bio_err);
        goto LAB_000373ac;
      }
      if ((local_238 == (char *)0x0) || (iVar6 = SSL_CTX_set_cipher_list(ctx,local_238), iVar6 != 0)
         ) {
        s = SSL_new(ctx);
        if (s != (SSL *)0x0) {
          if (!bVar4) goto LAB_0003736a;
          p_Var7 = (_STACK *)SSL_get_ciphers(s);
          for (iVar6 = 0; iVar8 = sk_num(p_Var7), iVar6 < iVar8; iVar6 = iVar6 + 1) {
            c = (SSL_CIPHER *)sk_value(p_Var7,iVar6);
            if (bVar2) {
              uVar9 = SSL_CIPHER_get_id(c);
              uVar11 = (uVar9 << 8) >> 0x18;
              uVar15 = (uVar9 << 0x10) >> 0x18;
              uVar16 = uVar9 & 0xff;
              if ((uVar9 & 0xff000000) == 0x2000000) {
                BIO_printf(bio,"     0x%02X,0x%02X,0x%02X - ",uVar11,uVar15,uVar16);
              }
              else if ((uVar9 & 0xff000000) == 0x3000000) {
                BIO_printf(bio,"          0x%02X,0x%02X - ",uVar15,uVar16);
              }
              else {
                BIO_printf(bio,"0x%02X,0x%02X,0x%02X,0x%02X - ",uVar9 >> 0x18,uVar11,uVar15,uVar16);
              }
            }
            pcVar12 = SSL_CIPHER_description(c,acStack_22c,0x200);
            BIO_puts(bio,pcVar12);
          }
          goto LAB_00037430;
        }
      }
      else {
        BIO_printf(bio_err,"Error in cipher list\n");
      }
    }
    SSL_load_error_strings();
    ERR_print_errors(bio_err);
    SSL_CTX_free(ctx);
    uVar14 = 1;
  }
LAB_000373ae:
  if (bio != (BIO *)0x0) {
    BIO_free_all(bio);
  }
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar14);
}

