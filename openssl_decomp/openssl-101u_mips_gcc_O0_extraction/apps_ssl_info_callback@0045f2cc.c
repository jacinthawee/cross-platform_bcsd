
void apps_ssl_info_callback(undefined4 param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if ((param_2 & 0x1000) == 0) {
    if ((param_2 & 0x2000) == 0) {
      pcVar3 = "undefined";
    }
    else {
      pcVar3 = "SSL_accept";
    }
  }
  else {
    pcVar3 = "SSL_connect";
  }
  if ((param_2 & 1) == 0) {
    if ((param_2 & 0x4000) == 0) {
      if ((param_2 & 2) != 0) {
        if (param_3 == 0) {
          uVar4 = *(undefined4 *)PTR_bio_err_006a6e3c;
          uVar1 = (*(code *)PTR_SSL_state_string_long_006a7c4c)();
          pcVar2 = "%s:failed in %s\n";
        }
        else {
          if (-1 < param_3) {
            return;
          }
          uVar4 = *(undefined4 *)PTR_bio_err_006a6e3c;
          uVar1 = (*(code *)PTR_SSL_state_string_long_006a7c4c)();
          pcVar2 = "%s:error in %s\n";
        }
        goto LAB_0045f330;
      }
    }
    else {
      if ((param_2 & 4) == 0) {
        pcVar3 = "SSL_write";
      }
      else {
        pcVar3 = "SSL_read";
      }
      uVar5 = *(undefined4 *)PTR_bio_err_006a6e3c;
      uVar1 = (*(code *)PTR_SSL_alert_type_string_long_006a7c50)(param_3);
      uVar4 = (*(code *)PTR_SSL_alert_desc_string_long_006a7c54)(param_3);
      (*(code *)PTR_BIO_printf_006a6e38)(uVar5,"SSL3 alert %s:%s:%s\n",pcVar3 + 4,uVar1,uVar4);
    }
    return;
  }
  uVar4 = *(undefined4 *)PTR_bio_err_006a6e3c;
  uVar1 = (*(code *)PTR_SSL_state_string_long_006a7c4c)();
  pcVar2 = "%s:%s\n";
LAB_0045f330:
                    /* WARNING: Could not recover jumptable at 0x0045f348. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BIO_printf_006a6e38)(uVar4,pcVar2,pcVar3,uVar1);
  return;
}

