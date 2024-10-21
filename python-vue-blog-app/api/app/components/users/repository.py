from app.database.base_repository import BaseRepository
from app.components.users.models import User

class UserRepository(BaseRepository):
  def __init__(self, _model):
    self._model = _model
    super().__init__(_model)


user_repository = UserRepository(User)