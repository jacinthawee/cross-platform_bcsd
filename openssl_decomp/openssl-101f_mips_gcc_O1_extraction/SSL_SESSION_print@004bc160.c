
int SSL_SESSION_print(BIO *fp,SSL_SESSION *ses)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined *puVar5;
  uchar *unaff_s0;
  uint uVar6;
  SSL_SESSION *unaff_s2;
  BIO *unaff_s3;
  undefined4 *local_28;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (ses == (SSL_SESSION *)0x0) goto LAB_004bc260;
  iVar2 = (*(code *)PTR_BIO_puts_006a8058)(fp,"SSL-Session:\n");
  unaff_s2 = ses;
  unaff_s3 = fp;
  if (iVar2 < 1) goto LAB_004bc260;
  iVar2 = ses->ssl_version;
  if (iVar2 == 2) {
    pcVar4 = "SSLv2";
  }
  else if (iVar2 == 0x300) {
    pcVar4 = "SSLv3";
  }
  else if (iVar2 == 0x303) {
    pcVar4 = "TLSv1.2";
  }
  else if (iVar2 == 0x302) {
    pcVar4 = "TLSv1.1";
  }
  else if (iVar2 == 0x301) {
    pcVar4 = "TLSv1";
  }
  else if (iVar2 == 0xfeff) {
    pcVar4 = "DTLSv1";
  }
  else if (iVar2 == 0x100) {
    pcVar4 = "DTLSv1-bad";
  }
  else {
    pcVar4 = "unknown";
  }
  iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(fp,"    Protocol  : %s\n",pcVar4);
  if (iVar2 < 1) goto LAB_004bc260;
  if (*(int *)(ses->krb5_client_princ + 0x24) != 0) {
    iVar2 = (*(code *)PTR_BIO_printf_006a7f38)
                      (fp,"    Cipher    : %s\n",
                       *(undefined4 *)(*(int *)(ses->krb5_client_princ + 0x24) + 4));
    if (iVar2 < 1) goto LAB_004bc260;
LAB_004bc2e0:
    iVar2 = (*(code *)PTR_BIO_puts_006a8058)(fp,"    Session-ID: ");
    if (iVar2 < 1) goto LAB_004bc260;
    if (ses->session_id_length != 0) {
      unaff_s0 = ses->session_id;
      uVar6 = 0;
      do {
        iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(fp,&DAT_00635448,*unaff_s0);
        if (iVar2 < 1) {
          uVar6 = 0;
          goto LAB_004bc264;
        }
        uVar6 = uVar6 + 1;
        unaff_s0 = unaff_s0 + 1;
      } while (uVar6 < ses->session_id_length);
    }
    iVar2 = (*(code *)PTR_BIO_puts_006a8058)(fp,"\n    Session-ID-ctx: ");
    if (iVar2 < 1) goto LAB_004bc260;
    if (ses->sid_ctx_length != 0) {
      unaff_s0 = ses->sid_ctx;
      uVar6 = 0;
      do {
        iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(fp,&DAT_00635448,*unaff_s0);
        if (iVar2 < 1) {
          uVar6 = 0;
          goto LAB_004bc264;
        }
        uVar6 = uVar6 + 1;
        unaff_s0 = unaff_s0 + 1;
      } while (uVar6 < ses->sid_ctx_length);
    }
    iVar2 = (*(code *)PTR_BIO_puts_006a8058)(fp,"\n    Master-Key: ");
    if (iVar2 < 1) goto LAB_004bc260;
    if (ses->master_key_length != 0) {
      unaff_s0 = ses->master_key;
      uVar6 = 0;
      do {
        iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(fp,&DAT_00635448,*unaff_s0);
        if (iVar2 < 1) {
          uVar6 = 0;
          goto LAB_004bc264;
        }
        uVar6 = uVar6 + 1;
        unaff_s0 = unaff_s0 + 1;
      } while (uVar6 < (uint)ses->master_key_length);
    }
    iVar2 = (*(code *)PTR_BIO_puts_006a8058)(fp,"\n    Key-Arg   : ");
    if (iVar2 < 1) goto LAB_004bc260;
    if (ses->key_arg_length == 0) {
      iVar2 = (*(code *)PTR_BIO_puts_006a8058)(fp,&DAT_00648594);
      if (iVar2 < 1) goto LAB_004bc260;
    }
    else {
      unaff_s0 = ses->key_arg;
      uVar6 = 0;
      do {
        iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(fp,&DAT_00635448,*unaff_s0);
        if (iVar2 < 1) {
          uVar6 = 0;
          goto LAB_004bc264;
        }
        uVar6 = uVar6 + 1;
        unaff_s0 = unaff_s0 + 1;
      } while (uVar6 < ses->key_arg_length);
    }
    iVar2 = (*(code *)PTR_BIO_puts_006a8058)(fp,"\n    PSK identity: ");
    if (iVar2 < 1) goto LAB_004bc260;
    puVar5 = *(undefined **)ses->krb5_client_princ;
    if (puVar5 == (undefined *)0x0) {
      puVar5 = &DAT_00648594;
    }
    unaff_s0 = "7 datafinal";
    iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(fp,"%s",puVar5);
    if (iVar2 < 1) goto LAB_004bc260;
    iVar2 = (*(code *)PTR_BIO_puts_006a8058)(fp,"\n    PSK identity hint: ");
    if (iVar2 < 1) goto LAB_004bc260;
    puVar5 = (undefined *)ses->krb5_client_princ_len;
    if (puVar5 == (undefined *)0x0) {
      puVar5 = &DAT_00648594;
    }
    iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(fp,"%s",puVar5);
    if (iVar2 < 1) goto LAB_004bc260;
    iVar2 = (*(code *)PTR_BIO_puts_006a8058)(fp,"\n    SRP username: ");
    if (iVar2 < 1) goto LAB_004bc260;
    puVar5 = *(undefined **)(ses->krb5_client_princ + 0x60);
    if (puVar5 == (undefined *)0x0) goto LAB_004bc76c;
    goto LAB_004bc610;
  }
  uVar6 = *(uint *)(ses->krb5_client_princ + 0x28);
  if ((uVar6 & 0xff000000) == 0x2000000) {
    iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(fp,"    Cipher    : %06lX\n",uVar6 & 0xffffff);
    if (0 < iVar2) goto LAB_004bc2e0;
    uVar6 = 0;
  }
  else {
    iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(fp,"    Cipher    : %04lX\n",uVar6 & 0xffff);
    if (0 < iVar2) goto LAB_004bc2e0;
    uVar6 = 0;
  }
LAB_004bc264:
  do {
    if (local_24 == *(int *)puVar1) {
      return uVar6;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_004bc76c:
    puVar5 = &DAT_00648594;
LAB_004bc610:
    iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(fp,unaff_s0 + 0x16dc,puVar5);
    unaff_s2 = ses;
    unaff_s3 = fp;
    if (iVar2 < 1) goto LAB_004bc260;
    if (*(int *)(ses->krb5_client_princ + 0x5c) == 0) {
LAB_004bc634:
      if (*(int *)(ses->krb5_client_princ + 0x54) == 0) {
LAB_004bc678:
        if (*(int *)(ses->krb5_client_princ + 0x20) != 0) {
          local_28 = (undefined4 *)0x0;
          ssl_cipher_get_evp(ses,0,0,0,0,&local_28);
          if (local_28 == (undefined4 *)0x0) {
            iVar2 = (*(code *)PTR_BIO_printf_006a7f38)
                              (fp,"\n    Compression: %d",
                               *(undefined4 *)(ses->krb5_client_princ + 0x20));
            if (iVar2 < 1) {
              uVar6 = 0;
              goto LAB_004bc264;
            }
          }
          else {
            iVar2 = (*(code *)PTR_BIO_printf_006a7f38)
                              (fp,"\n    Compression: %d (%s)",*local_28,
                               *(undefined4 *)(local_28[2] + 4));
            if (iVar2 < 1) goto LAB_004bc260;
          }
        }
        if (*(int *)(ses->krb5_client_princ + 0x1c) != 0) {
          iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(fp,"\n    Start Time: %ld");
          if (iVar2 < 1) {
            uVar6 = 0;
            goto LAB_004bc264;
          }
        }
        if (*(int *)(ses->krb5_client_princ + 0x18) != 0) {
          iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(fp,"\n    Timeout   : %ld (sec)");
          if (iVar2 < 1) goto LAB_004bc260;
        }
        iVar2 = (*(code *)PTR_BIO_puts_006a8058)(fp,"\n");
        if (0 < iVar2) {
          iVar2 = (*(code *)PTR_BIO_puts_006a8058)(fp,"    Verify return code: ");
          if (0 < iVar2) {
            unaff_s0 = *(uchar **)(ses->krb5_client_princ + 0x10);
            uVar3 = (*(code *)PTR_X509_verify_cert_error_string_006a839c)(unaff_s0);
            iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(fp,"%ld (%s)\n",unaff_s0,uVar3);
            uVar6 = (uint)(0 < iVar2);
            goto LAB_004bc264;
          }
        }
      }
      else {
        iVar2 = (*(code *)PTR_BIO_puts_006a8058)(fp,"\n    TLS session ticket:\n");
        if (0 < iVar2) {
          iVar2 = (*(code *)PTR_BIO_dump_indent_006a8434)
                            (fp,*(undefined4 *)(ses->krb5_client_princ + 0x54),
                             *(undefined4 *)(ses->krb5_client_princ + 0x58),4);
          if (0 < iVar2) goto LAB_004bc678;
        }
      }
LAB_004bc260:
      uVar6 = 0;
      ses = unaff_s2;
      fp = unaff_s3;
      goto LAB_004bc264;
    }
    iVar2 = (*(code *)PTR_BIO_printf_006a7f38)
                      (fp,"\n    TLS session ticket lifetime hint: %ld (seconds)");
    if (0 < iVar2) goto LAB_004bc634;
    uVar6 = 0;
  } while( true );
}

