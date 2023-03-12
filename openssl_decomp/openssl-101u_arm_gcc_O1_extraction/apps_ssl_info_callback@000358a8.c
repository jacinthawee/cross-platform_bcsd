
void apps_ssl_info_callback(SSL *param_1,uint param_2,int param_3)

{
  BIO *bio;
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  
  bio = bio_err;
  if ((int)(param_2 << 0x1f) < 0) {
    SSL_state_string_long(param_1);
    pcVar3 = "%s:%s\n";
LAB_0003596c:
    BIO_vprintf(bio,pcVar3,&stack0xfffffff8);
    return;
  }
  if ((int)(param_2 << 0x11) < 0) {
    pcVar3 = "SSL_read";
    if ((param_2 & 4) == 0) {
      pcVar3 = "SSL_write";
    }
    pcVar1 = SSL_alert_type_string_long(param_3);
    pcVar2 = SSL_alert_desc_string_long(param_3);
    BIO_printf(bio,"SSL3 alert %s:%s:%s\n",pcVar3 + 4,pcVar1,pcVar2);
  }
  else if ((int)(param_2 << 0x1e) < 0) {
    if (param_3 == 0) {
      SSL_state_string_long(param_1);
      pcVar3 = "%s:failed in %s\n";
    }
    else {
      if (-1 < param_3) {
        return;
      }
      SSL_state_string_long(param_1);
      pcVar3 = "%s:error in %s\n";
    }
    goto LAB_0003596c;
  }
  return;
}

