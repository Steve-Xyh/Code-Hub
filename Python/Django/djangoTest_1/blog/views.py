from django.shortcuts import render
from django.http import HttpResponse
from blog.models import Article


# Create your views here.


def hello_world(request):
    return HttpResponse('Hello World Django Test')


def article_content(request):
    article = Article.objects.all()[0]
    title = article.title
    brief_content = article.brief_content
    content = article.content
    article_id = article.article_id
    publish_date = article.publish_date
    return_str = 'title: %s | \n' \
                 'brief_content: %s | \n' \
                 'content: %s | \n' \
                 'article_id: %s | \n' \
                 'publish_date: %s \n' \
                 % (title, brief_content, content, article_id, publish_date)
    return HttpResponse(return_str)


def get_index_page(request):
    all_article = Article.objects.all()
    return render(request, 'blog/index.html', {
                      'article_list': all_article
                  })


def get_detail_page(request):
	curr_article = Article.objects.all()[0]
	return render(request, 'blog/detail.html', {
                      'curr_article': curr_article
                  })