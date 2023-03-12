
int SSL_SESSION_print(BIO *fp,SSL_SESSION *ses)

{
  int iVar1;
  char *pcVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar3;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  uint uVar4;
  int in_GS_OFFSET;
  undefined4 uVar5;
  undefined4 *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((ses != (SSL_SESSION *)0x0) && (iVar1 = BIO_puts(fp,"SSL-Session:\n"), 0 < iVar1)) {
    iVar1 = ses->ssl_version;
    pcVar2 = "SSLv2";
    if (((iVar1 != 2) &&
        ((((pcVar2 = "SSLv3", iVar1 != 0x300 && (pcVar2 = "TLSv1.2", iVar1 != 0x303)) &&
          (pcVar2 = "TLSv1.1", iVar1 != 0x302)) &&
         ((pcVar2 = "TLSv1", iVar1 != 0x301 && (pcVar2 = "DTLSv1", iVar1 != 0xfeff)))))) &&
       (pcVar2 = "DTLSv1-bad", iVar1 != 0x100)) {
      pcVar2 = "unknown";
    }
    iVar1 = BIO_printf(fp,"    Protocol  : %s\n",pcVar2);
    if (0 < iVar1) {
      if (*(int *)(ses->krb5_client_princ + 0x24) == 0) {
        uVar4 = *(uint *)(ses->krb5_client_princ + 0x28);
        if ((uVar4 & 0xff000000) == 0x2000000) {
          uVar4 = uVar4 & 0xffffff;
          pcVar2 = "    Cipher    : %06lX\n";
        }
        else {
          uVar4 = uVar4 & 0xffff;
          pcVar2 = "    Cipher    : %04lX\n";
        }
      }
      else {
        uVar4 = *(uint *)(*(int *)(ses->krb5_client_princ + 0x24) + 4);
        pcVar2 = "    Cipher    : %s\n";
      }
      iVar1 = BIO_printf(fp,pcVar2,uVar4);
      if ((0 < iVar1) && (iVar1 = BIO_puts(fp,"    Session-ID: "), 0 < iVar1)) {
        uVar4 = 0;
        if (ses->session_id_length != 0) {
          do {
            iVar1 = BIO_printf(fp,"%02X",(uint)ses->session_id[uVar4]);
            if (iVar1 < 1) goto LAB_080cf4b8;
            uVar4 = uVar4 + 1;
          } while (uVar4 < ses->session_id_length);
        }
        iVar1 = BIO_puts(fp,"\n    Session-ID-ctx: ");
        if (0 < iVar1) {
          uVar4 = 0;
          if (ses->sid_ctx_length != 0) {
            do {
              iVar1 = BIO_printf(fp,"%02X",(uint)ses->sid_ctx[uVar4]);
              if (iVar1 < 1) goto LAB_080cf4b8;
              uVar4 = uVar4 + 1;
            } while (uVar4 < ses->sid_ctx_length);
          }
          iVar1 = BIO_puts(fp,"\n    Master-Key: ");
          if (0 < iVar1) {
            uVar4 = 0;
            if (ses->master_key_length != 0) {
              do {
                iVar1 = BIO_printf(fp,"%02X",(uint)ses->master_key[uVar4]);
                if (iVar1 < 1) goto LAB_080cf4b8;
                uVar4 = uVar4 + 1;
              } while (uVar4 < (uint)ses->master_key_length);
            }
            iVar1 = BIO_puts(fp,"\n    Key-Arg   : ");
            if (0 < iVar1) {
              uVar4 = 0;
              if (ses->key_arg_length == 0) {
                iVar1 = BIO_puts(fp,"None");
                if (iVar1 < 1) goto LAB_080cf4b8;
              }
              else {
                do {
                  iVar1 = BIO_printf(fp,"%02X",(uint)ses->key_arg[uVar4]);
                  if (iVar1 < 1) goto LAB_080cf4b8;
                  uVar4 = uVar4 + 1;
                } while (uVar4 < ses->key_arg_length);
              }
              iVar1 = BIO_puts(fp,"\n    PSK identity: ");
              if (0 < iVar1) {
                pcVar2 = *(char **)ses->krb5_client_princ;
                if (pcVar2 == (char *)0x0) {
                  pcVar2 = "None";
                }
                iVar1 = BIO_printf(fp,"%s",pcVar2);
                if ((0 < iVar1) && (iVar1 = BIO_puts(fp,"\n    PSK identity hint: "), 0 < iVar1)) {
                  pcVar2 = (char *)ses->krb5_client_princ_len;
                  if (pcVar2 == (char *)0x0) {
                    pcVar2 = "None";
                  }
                  iVar1 = BIO_printf(fp,"%s",pcVar2);
                  if ((0 < iVar1) && (iVar1 = BIO_puts(fp,"\n    SRP username: "), 0 < iVar1)) {
                    pcVar2 = *(char **)(ses->krb5_client_princ + 0x60);
                    if (pcVar2 == (char *)0x0) {
                      pcVar2 = "None";
                    }
                    iVar1 = BIO_printf(fp,"%s",pcVar2);
                    if (((0 < iVar1) &&
                        ((uVar3 = extraout_EDX, *(int *)(ses->krb5_client_princ + 0x5c) == 0 ||
                         (iVar1 = BIO_printf(fp,
                                             "\n    TLS session ticket lifetime hint: %ld (seconds)"
                                             ,*(int *)(ses->krb5_client_princ + 0x5c)),
                         uVar3 = extraout_EDX_01, 0 < iVar1)))) &&
                       ((*(int *)(ses->krb5_client_princ + 0x54) == 0 ||
                        ((iVar1 = BIO_puts(fp,"\n    TLS session ticket:\n"), 0 < iVar1 &&
                         (iVar1 = BIO_dump_indent(fp,*(char **)(ses->krb5_client_princ + 0x54),
                                                  *(int *)(ses->krb5_client_princ + 0x58),4),
                         uVar3 = extraout_EDX_00, 0 < iVar1)))))) {
                      if (*(int *)(ses->krb5_client_princ + 0x20) != 0) {
                        local_14 = (undefined4 *)0x0;
                        ssl_cipher_get_evp(ses,0,0,0,0,&local_14,"None","None");
                        if (local_14 == (undefined4 *)0x0) {
                          uVar5 = *(undefined4 *)(ses->krb5_client_princ + 0x20);
                          pcVar2 = "\n    Compression: %d";
                          uVar3 = extraout_ECX;
                        }
                        else {
                          uVar3 = *(undefined4 *)(local_14[2] + 4);
                          uVar5 = *local_14;
                          pcVar2 = "\n    Compression: %d (%s)";
                        }
                        iVar1 = BIO_printf(fp,pcVar2,uVar5,uVar3);
                        uVar3 = extraout_EDX_02;
                        if (iVar1 < 1) goto LAB_080cf4b8;
                      }
                      if ((((*(int *)(ses->krb5_client_princ + 0x1c) == 0) ||
                           (iVar1 = BIO_printf(fp,"\n    Start Time: %ld",
                                               *(int *)(ses->krb5_client_princ + 0x1c),uVar3),
                           0 < iVar1)) &&
                          ((*(int *)(ses->krb5_client_princ + 0x18) == 0 ||
                           (iVar1 = BIO_printf(fp,"\n    Timeout   : %ld (sec)",
                                               *(int *)(ses->krb5_client_princ + 0x18)), 0 < iVar1))
                          )) && ((iVar1 = BIO_puts(fp,"\n"), 0 < iVar1 &&
                                 (iVar1 = BIO_puts(fp,"    Verify return code: "), 0 < iVar1)))) {
                        pcVar2 = X509_verify_cert_error_string
                                           (*(long *)(ses->krb5_client_princ + 0x10));
                        iVar1 = BIO_printf(fp,"%ld (%s)\n",
                                           *(undefined4 *)(ses->krb5_client_princ + 0x10),pcVar2);
                        uVar4 = (uint)(0 < iVar1);
                        goto LAB_080cf4ba;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_080cf4b8:
  uVar4 = 0;
LAB_080cf4ba:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}

