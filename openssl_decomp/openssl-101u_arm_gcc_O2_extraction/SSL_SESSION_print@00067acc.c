
/* WARNING: Type propagation algorithm not settling */

int SSL_SESSION_print(BIO *fp,SSL_SESSION *ses)

{
  uchar *puVar1;
  int iVar2;
  char *pcVar3;
  undefined *puVar4;
  long n;
  uint uVar5;
  undefined4 *local_14;
  
  if ((ses != (SSL_SESSION *)0x0) && (iVar2 = BIO_puts(fp,"SSL-Session:\n"), 0 < iVar2)) {
    iVar2 = ses->ssl_version;
    if (iVar2 == 2) {
      pcVar3 = "SSLv2";
    }
    else if (iVar2 == 0x300) {
      pcVar3 = "SSLv3";
    }
    else if (iVar2 == 0x303) {
      pcVar3 = "TLSv1.2";
    }
    else if (iVar2 == 0x302) {
      pcVar3 = "TLSv1.1";
    }
    else if (iVar2 == 0x301) {
      pcVar3 = "TLSv1";
    }
    else if (iVar2 == 0xfeff) {
      pcVar3 = "DTLSv1";
    }
    else {
      pcVar3 = "DTLSv1-bad";
      if (iVar2 != 0x100) {
        pcVar3 = "unknown";
      }
    }
    iVar2 = BIO_printf(fp,"    Protocol  : %s\n",pcVar3);
    if (0 < iVar2) {
      if (*(int *)(ses->krb5_client_princ + 0x24) == 0) {
        uVar5 = *(uint *)(ses->krb5_client_princ + 0x28);
        if ((uVar5 & 0xff000000) == 0x2000000) {
          iVar2 = BIO_printf(fp,"    Cipher    : %06lX\n",uVar5 & 0xffffff);
        }
        else {
          iVar2 = BIO_printf(fp,"    Cipher    : %04lX\n",uVar5 & 0xffff);
        }
      }
      else {
        iVar2 = BIO_printf(fp,"    Cipher    : %s\n",
                           *(undefined4 *)(*(int *)(ses->krb5_client_princ + 0x24) + 4));
      }
      if ((0 < iVar2) && (iVar2 = BIO_puts(fp,"    Session-ID: "), 0 < iVar2)) {
        uVar5 = 0;
        if (ses->session_id_length != 0) {
          do {
            puVar1 = ses->session_id + uVar5;
            uVar5 = uVar5 + 1;
            iVar2 = BIO_printf(fp,"%02X",(uint)*puVar1);
            if (iVar2 < 1) {
              return 0;
            }
          } while (uVar5 < ses->session_id_length);
        }
        iVar2 = BIO_puts(fp,"\n    Session-ID-ctx: ");
        if (0 < iVar2) {
          uVar5 = 0;
          if (ses->sid_ctx_length != 0) {
            do {
              puVar1 = ses->sid_ctx + uVar5;
              uVar5 = uVar5 + 1;
              iVar2 = BIO_printf(fp,"%02X",(uint)*puVar1);
              if (iVar2 < 1) {
                return 0;
              }
            } while (uVar5 < ses->sid_ctx_length);
          }
          iVar2 = BIO_puts(fp,"\n    Master-Key: ");
          if (0 < iVar2) {
            uVar5 = 0;
            if (ses->master_key_length != 0) {
              do {
                puVar1 = ses->master_key + uVar5;
                uVar5 = uVar5 + 1;
                iVar2 = BIO_printf(fp,"%02X",(uint)*puVar1);
                if (iVar2 < 1) {
                  return 0;
                }
              } while (uVar5 < (uint)ses->master_key_length);
            }
            iVar2 = BIO_puts(fp,"\n    Key-Arg   : ");
            if (0 < iVar2) {
              uVar5 = 0;
              if (ses->key_arg_length == 0) {
                iVar2 = BIO_puts(fp,"None");
                if (iVar2 < 1) {
                  return 0;
                }
              }
              else {
                do {
                  puVar1 = ses->key_arg + uVar5;
                  uVar5 = uVar5 + 1;
                  iVar2 = BIO_printf(fp,"%02X",(uint)*puVar1);
                  if (iVar2 < 1) {
                    return 0;
                  }
                } while (uVar5 < ses->key_arg_length);
              }
              iVar2 = BIO_puts(fp,"\n    PSK identity: ");
              if (0 < iVar2) {
                puVar4 = *(undefined **)ses->krb5_client_princ;
                if (*(undefined **)ses->krb5_client_princ == (undefined *)0x0) {
                  puVar4 = &DAT_0013ae2c;
                }
                iVar2 = BIO_printf(fp,"%s",puVar4);
                if ((0 < iVar2) && (iVar2 = BIO_puts(fp,"\n    PSK identity hint: "), 0 < iVar2)) {
                  puVar4 = (undefined *)ses->krb5_client_princ_len;
                  if ((undefined *)ses->krb5_client_princ_len == (undefined *)0x0) {
                    puVar4 = &DAT_0013ae2c;
                  }
                  iVar2 = BIO_printf(fp,"%s",puVar4);
                  if ((0 < iVar2) && (iVar2 = BIO_puts(fp,"\n    SRP username: "), 0 < iVar2)) {
                    puVar4 = *(undefined **)(ses->krb5_client_princ + 0x60);
                    if (*(undefined **)(ses->krb5_client_princ + 0x60) == (undefined *)0x0) {
                      puVar4 = &DAT_0013ae2c;
                    }
                    iVar2 = BIO_printf(fp,"%s",puVar4);
                    if (((0 < iVar2) &&
                        ((*(int *)(ses->krb5_client_princ + 0x5c) == 0 ||
                         (iVar2 = BIO_printf(fp,
                                             "\n    TLS session ticket lifetime hint: %ld (seconds)"
                                            ), 0 < iVar2)))) &&
                       ((*(int *)(ses->krb5_client_princ + 0x54) == 0 ||
                        ((iVar2 = BIO_puts(fp,"\n    TLS session ticket:\n"), 0 < iVar2 &&
                         (iVar2 = BIO_dump_indent(fp,*(undefined4 *)(ses->krb5_client_princ + 0x54),
                                                  *(undefined4 *)(ses->krb5_client_princ + 0x58),4),
                         0 < iVar2)))))) {
                      if (*(int *)(ses->krb5_client_princ + 0x20) != 0) {
                        local_14 = (undefined4 *)0x0;
                        ssl_cipher_get_evp(ses,0,0,0,0,&local_14);
                        if (local_14 == (undefined4 *)0x0) {
                          iVar2 = BIO_printf(fp,"\n    Compression: %d",
                                             *(undefined4 *)(ses->krb5_client_princ + 0x20));
                        }
                        else {
                          iVar2 = BIO_printf(fp,"\n    Compression: %d (%s)",*local_14,
                                             *(undefined4 *)(local_14[2] + 4));
                        }
                        if (iVar2 < 1) {
                          return 0;
                        }
                      }
                      if ((((*(int *)(ses->krb5_client_princ + 0x1c) == 0) ||
                           (iVar2 = BIO_printf(fp,"\n    Start Time: %ld"), 0 < iVar2)) &&
                          ((*(int *)(ses->krb5_client_princ + 0x18) == 0 ||
                           (iVar2 = BIO_printf(fp,"\n    Timeout   : %ld (sec)"), 0 < iVar2)))) &&
                         ((iVar2 = BIO_puts(fp,"\n"), 0 < iVar2 &&
                          (iVar2 = BIO_puts(fp,"    Verify return code: "), 0 < iVar2)))) {
                        n = *(long *)(ses->krb5_client_princ + 0x10);
                        pcVar3 = X509_verify_cert_error_string(n);
                        iVar2 = BIO_printf(fp,"%ld (%s)\n",n,pcVar3);
                        return (uint)(0 < iVar2);
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
  return 0;
}

