
int X509_TRUST_set_default(int param_1,X509 *param_2,int param_3)

{
  undefined *puVar1;
  
  puVar1 = default_trust;
  default_trust = (undefined *)param_1;
  return (int)puVar1;
}

