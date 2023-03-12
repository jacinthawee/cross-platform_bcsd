
char trust_compat(undefined4 param_1,X509 *param_2)

{
  X509_check_purpose(param_2,-1,0);
  return (-((param_2->ex_flags & 0x20) == 0) & 2U) + 1;
}

