
void apps_ssl_info_callback(SSL *param_1,uint param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = "SSL_connect";
  if (((param_2 & 0x1000) == 0) && (pcVar3 = "undefined", (param_2 & 0x2000) != 0)) {
    pcVar3 = "SSL_accept";
  }
  if ((param_2 & 1) == 0) {
    if ((param_2 & 0x4000) == 0) {
      if ((param_2 & 2) != 0) {
        if (param_3 == 0) {
          pcVar1 = SSL_state_string_long(param_1);
          BIO_printf(bio_err,"%s:failed in %s\n",pcVar3,pcVar1);
        }
        else if (param_3 < 0) {
          pcVar1 = SSL_state_string_long(param_1);
          BIO_printf(bio_err,"%s:error in %s\n",pcVar3,pcVar1);
        }
      }
    }
    else {
      pcVar3 = "write";
      if ((param_2 & 4) != 0) {
        pcVar3 = "read";
      }
      pcVar1 = SSL_alert_desc_string_long(param_3);
      pcVar2 = SSL_alert_type_string_long(param_3);
      BIO_printf(bio_err,"SSL3 alert %s:%s:%s\n",pcVar3,pcVar2,pcVar1);
    }
    return;
  }
  pcVar1 = SSL_state_string_long(param_1);
  BIO_printf(bio_err,"%s:%s\n",pcVar3,pcVar1);
  return;
}

