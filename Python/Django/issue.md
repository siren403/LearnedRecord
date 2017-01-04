### issues

version 1.10

  urls.py에서 url함수에서 view를 넘길 시 문자열이 아닌
  대상 view를 import하여 넘김
  ex)
    from app.views import view
    urlpatterns = [
      url(r'^app/$',view)
    ]
