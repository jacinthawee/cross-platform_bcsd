
void asn1_bio_puts(undefined4 param_1,char *param_2)

{
  size_t sVar1;
  
  sVar1 = strlen(param_2);
  asn1_bio_write(param_1,param_2,sVar1);
  return;
}

