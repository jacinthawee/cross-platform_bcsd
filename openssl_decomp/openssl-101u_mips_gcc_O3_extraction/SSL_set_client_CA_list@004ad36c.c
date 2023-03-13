
void SSL_set_client_CA_list(SSL *s,stack_st_X509_NAME *name_list)

{
  int iVar1;
  undefined4 in_a2;
  undefined4 in_a3;
  
  iVar1 = (s->ex_data).dummy;
  if (iVar1 != 0) {
    (*(code *)PTR_sk_pop_free_006a7058)(iVar1,PTR_X509_NAME_free_006a6ff8,in_a2,in_a3,&_gp);
  }
  (s->ex_data).dummy = (int)name_list;
  return;
}

