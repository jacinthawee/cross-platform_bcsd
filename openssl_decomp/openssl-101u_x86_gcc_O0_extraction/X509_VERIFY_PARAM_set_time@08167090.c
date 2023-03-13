
void X509_VERIFY_PARAM_set_time(X509_VERIFY_PARAM *param,time_t t)

{
  param->flags = param->flags | 2;
  param->check_time = t;
  return;
}

